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
	tableID = "id"
	tasksTableName = "tasks"
	tasksDescription = "description"
	tasksIsCompleted = "is_completed"
	tasksUserID = "user_id"
	tasksID = "id"
)

// FormStruct represents html form POST struct 
type FormStruct struct {
	Username string
	Password string
}

// RegisterForm represents html form POST struct for checking and adding to database
type RegisterForm struct {
	Username string
	Password string
	Re_Password string
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

// Define a struct to return user ID and authentication status
type AuthResult struct {
	UserID int
	IsAuthenticated bool
}

type Task struct {
	Description string
	ID int
}

type ToDoPassStruct struct {
	Tasks  []Task
	UserID int
}

// NewForm return FormStruct struct
func NewForm (username, password string) *FormStruct {
	return &FormStruct{
		Username: username,
		Password: password,
	}
}

// NewRegisterForm return FormStruct struct
func NewRegisterForm (username, password, re_password string) *RegisterForm {
	return &RegisterForm{
		Username: username,
		Password: password,
		Re_Password: re_password,
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

// CheckUserNameAndPassword checks if a username and hashed password combination exists in the database
func (database *DataBaseProps) CheckUserNameAndPassword(Username string, Password string) (AuthResult, error) {
	if database == nil || database.Connection == nil {
		return AuthResult{}, fmt.Errorf("database connection is nil")
	}

	var (
		storedHashPassword string
		userID             int
	)

	// Update the query to select both the hashed password and user ID
	scriptToFindUser := fmt.Sprintf("SELECT %s, %s FROM %s WHERE %s = $1 LIMIT 1", tableHashedPassword, tableID, tableName, tableUsername)
	row := database.Connection.QueryRow(scriptToFindUser, Username)
	
	err := row.Scan(&storedHashPassword, &userID)
	if err != nil {
		if err == sql.ErrNoRows {
			return AuthResult{}, nil // No rows means user not found
		}
		return AuthResult{}, err
	}

	if ComparePassword(Password, storedHashPassword) {
		return AuthResult{UserID: userID, IsAuthenticated: true}, nil
	}

	return AuthResult{IsAuthenticated: false}, nil
}

func (database *DataBaseProps) DoesUserExist (Username string) (bool, error) {
	if database == nil || database.Connection == nil {
		return false, fmt.Errorf("database connection is nil")
	}

	var scriptToFindUser string = fmt.Sprintf("SELECT 1 FROM %s WHERE %s = $1 LIMIT 1", tableName, tableUsername)
	row := database.Connection.QueryRow(scriptToFindUser, Username)
	
	var exists int
	err := row.Scan(&exists)
	if err != nil {
		if err == sql.ErrNoRows {
			return false, nil
		}
		return false, err
	}

	return exists == 1, nil
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

func (database *DataBaseProps) GetUsername(userID int) (string, error) {
	query := fmt.Sprintf("SELECT %s FROM %s WHERE %s = $1 LIMIT 1", tableUsername, tableName, tableID)

	var result string
	err := database.Connection.QueryRow(query, userID).Scan(&result)
	if err != nil {
		if err == sql.ErrNoRows {
			return "", fmt.Errorf("no user found with ID %d", userID)
		}
		return "", fmt.Errorf("failed to retrieve username: %v", err)
	}

	return result, nil
}


func (database *DataBaseProps) AddTask (userID int, task string) error {
	query := fmt.Sprintf(`INSERT INTO %s (%s, %s) VALUES ($1, $2)`, tasksTableName, tasksUserID, tasksDescription)

	_, err := database.Connection.Exec(query, userID, task)
	if err != nil {
		return fmt.Errorf("insert into error : %v", err)
	}

	return nil
}

func (database *DataBaseProps) GetTasksFromDatabase (userID int) ([]Task, error) {
	if database == nil || database.Connection == nil {
		return nil, fmt.Errorf("database connection is nil")
	}

	var query string = fmt.Sprintf("SELECT %s, %s FROM %s WHERE %s = $1", tasksDescription, tasksID, tasksTableName, tasksUserID)
	rows, err := database.Connection.Query(query, userID)
	if err != nil {
		return nil, fmt.Errorf("row query error : %v", err)
	}
	defer rows.Close()

	var result []Task = []Task{}

	for rows.Next() {
		var description string
		var id int
		if err := rows.Scan(&description, &id); err != nil {
			return nil, fmt.Errorf("row scan error: %v", err)
		}

		result = append(result, Task{ID: id, Description: description})
	}

	if err := rows.Err(); err != nil {
		return nil, fmt.Errorf("rows iteration error: %v", err)
	}

	return result, nil
}

func (database *DataBaseProps) DeleteTask(userID int, taskID int) error {
	if database == nil || database.Connection == nil {
		return fmt.Errorf("database connection is nil")
	}

	query := fmt.Sprintf("DELETE FROM %s WHERE %s = $1 AND %s = $2", tasksTableName, tasksUserID, tasksID)
	_, err := database.Connection.Exec(query, userID, taskID)
	if err != nil {
		return fmt.Errorf("row delete error: %v", err)
	}

	return nil
}