package packages

import (
	"database/sql"
	"fmt"
	"log"

	_ "github.com/lib/pq"
)

// Database table and columns name
const (
	tableName = "todouserpasswords"
	tableUsername = "Username"
	tableHashedPassword = "HashedPassword"
)

// FormStruct represents html form POST struct 
type FormStruct struct {
	Username string
	Password string
}

// RowOfDatabase represents a row in the database, linked to the next row
type RowOfDatabase struct {
	ID             int64
	Username       string
	HashedPassword string
	Next           *RowOfDatabase
}

// DataBaseProps holds the properties needed to connect and manipulate the database
type DataBaseProps struct {
	databaseName string
	host         string
	port         string
	user         string
	password     string
	Connection   *sql.DB
}

// NewForm return FormStruct struct
func NewForm (username, password string) *FormStruct {
	return &FormStruct{
		Username: username,
		Password: password,
	}
}

// NewDatabaseConnection creates a new database connection and returns DataBaseProps and an error if there is an issue
func NewDatabaseConnection(databaseName, host, port, user, password string) (*DataBaseProps, error) {
	databaseProps := &DataBaseProps{
		databaseName: databaseName,
		host:         host,
		port:         port,
		user:         user,
		password:     password,
	}

	err := databaseProps.ConnectTodatabase()
	if err != nil {
		return nil, err
	}

	fmt.Printf("Database connection is successful\n")

	return databaseProps, nil
}

// connString returns the connection string for the database
func (database *DataBaseProps) connString() string {
	return fmt.Sprintf("host=%s port=%s user=%s password=%s databasename=%s sslmode=disable", database.host, database.port, database.user, database.password, database.databaseName)
}

// ConnectTodatabase tries to connect to the database and sets the Connection field, returning any connection error
func (database *DataBaseProps) ConnectTodatabase() error {
	var err error
	database.Connection, err = sql.Open("postgres", database.connString())
	if err != nil {
		log.Printf("Error during connection: %v\n", err)
		return err
	}

	if err = database.Connection.Ping(); err != nil {
		log.Printf("Error during pinging database: %v", err)
		return err
	}

	fmt.Println("Database connection was successful")
	return nil
}

// ExecuteScript executes a script (INSERT INTO, DROP COLUMN, etc.) and returns the number of affected rows, the last inserted ID, and any error
func (database *DataBaseProps) ExecuteScript(script string, args ...any) (int64, error) {
	result, err := database.Connection.Exec(script, args...)
	if err != nil {
		return -1, err
	}

	rowsAffected, err := result.RowsAffected()
	if err != nil {
		return -1, err
	}

	fmt.Printf("Script %s has been successfully executed\n", script)

	return rowsAffected, nil
}

// ExecuteQuery executes a SELECT query and returns the result as a linked list of RowOfDatabase and any error
func (database *DataBaseProps) ExecuteQuery(script string, args ...any) (*RowOfDatabase, error) {
	rows, err := database.Connection.Query(script, args...)
	if err != nil {
		return nil, err
	}
	defer rows.Close()

	var head, current *RowOfDatabase

	for rows.Next() {
		var row RowOfDatabase
		err := rows.Scan(&row.ID, &row.Username, &row.HashedPassword)
		if err != nil {
			return nil, err
		}

		if head == nil {
			head = &row
			current = head
		} else {
			current.Next = &row
			current = current.Next
		}
	}

	if err := rows.Err(); err != nil {
		return nil, err
	}

	fmt.Printf("Query %s hass been successfully executed\n", script)

	return head, nil
}

// ExecuteQueryRow executes a query that returns a single row
func (database *DataBaseProps) ExecuteQueryRow(script string, args ...any) (*RowOfDatabase, error) {
	row := database.Connection.QueryRow(script, args...)
	var result RowOfDatabase
	err := row.Scan(&result.ID, &result.Username, &result.HashedPassword)
	if err != nil {
		if err == sql.ErrNoRows {
			return nil, nil // No row found
		}
		return nil, err
	}

	fmt.Printf("Query %s hass been successfully executed", script)
	return &result, nil
}


// Closedatabase closes the database connection and returns any error encountered
func (database *DataBaseProps) Closedatabase() error {
	err := database.Connection.Close()
	if err != nil {
		log.Printf("Error during closing the database: %v\n", err)
	}

	fmt.Println("Database has been successfully closed")
	return err
}

// DisplayData prints the data in the linked list and returns the count of printed rows
func (head *RowOfDatabase) DisplayData () (int64) {
	var printedCounter int64
	var current *RowOfDatabase = head
	for ; current != nil ; {
		printedCounter++
		fmt.Printf("ID : %d,\nUsername : %s\nHashed Password : %s\n", current.ID, current.Username, current.HashedPassword)
		current = current.Next
	}

	return printedCounter
}

//CheckUserNameAndPassword checks if a username and hashed password combination exists in the database
func (database *DataBaseProps) CheckUserNameAndPassword (Username string, Password string) (bool, error) {
	if database == nil || database.Connection == nil {
		return false, fmt.Errorf("database connection is nil")
	}

	var scriptToFindUser string = fmt.Sprintf("SELECT %s FROM %s WHERE %s = $1 LIMIT 1", tableHashedPassword, tableName, tableUsername)
	row := database.Connection.QueryRow(scriptToFindUser, Username)
	
	var storedHashPassword string
	err := row.Scan(&storedHashPassword)
	if err != nil {
		if err == sql.ErrNoRows {
			return false, nil
		}
		return false, err
	}

	if ComparePassword(Password, storedHashPassword) {
		return true, nil
	}

	return false, nil
}

// CreateNewUser creates a new user in the database with the given username and password
func (database *DataBaseProps) CreateNewUser (Username, Password string) error {
	if database == nil || database.Connection == nil {
		return fmt.Errorf("database connection is nil")
	}

	hashedPassword, err := HashPassword(Password)
	if err != nil {
		return err
	}

	query := fmt.Sprintf("INSERT INTO %s (%s, %s) VALUES ($1, $2)", tableName, tableUsername, tableHashedPassword)
	_, err = database.Connection.Exec(query, Username, hashedPassword)
	if err != nil {
		return err
	}

	fmt.Printf("User %s has been successfully created\n", Username)
	return nil
}