package dbplus

import (
	"database/sql"
	_ "github.com/lib/pq"
	"fmt"
	"time"
)

type DataBaseProps struct {
	Database string
	Host string
	Port string
	User string
	Password string
	Connection *sql.DB
}

func (db *DataBaseProps) connString () string {
	return fmt.Sprintf("host=%s port=%s user=%s password=%s dbname=%s sslmode=disable", db.Host, db.Port, db.User, db.Password, db.Database)
}

func (db *DataBaseProps) ConnectToDB () error {
	var databaseConnectionError error

	db.Connection, databaseConnectionError = sql.Open("postgres", db.connString())
	
	if databaseConnectionError != nil {
		fmt.Printf("During connection, error has been aquired: %v\n", databaseConnectionError)
		return databaseConnectionError
	}

	if err := db.Connection.Ping(); err != nil {
		fmt.Printf("During pinging the database %s, error has been aquired: %v\n", db.Database, err)
		return err	
	}

	fmt.Printf("Database connection was succesfull\nError: %v\n", databaseConnectionError)
	return nil
}

func (db *DataBaseProps) INSERT_INTO (args ...interface{}) error {
	if db.Connection == nil {
		var err error = fmt.Errorf("No database connection")
		fmt.Println(err)
		return err
	}

	var err error
	for _, arg := range args {
		var query string = fmt.Sprint("INSERT INTO passwords (passwordOfUser, dateOfInsert) VALUES ($1, $2)")
		_, err = db.Connection.Exec(query, arg, time.Now().Format("2006-01-02"))	
		if err != nil {
			fmt.Printf("During completing the query, error has been aquired: %v\n", err)
			return err
		}
	}

	fmt.Printf("Password was inserted: %s\n", args...)
	return nil
}

func (db *DataBaseProps) CloseTheDB () error {
	var err error = db.Connection.Close()
	if err != nil {
		fmt.Printf("During closing, error has been aquired: %v\n", err)
	}

	return err
}