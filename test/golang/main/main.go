// package main

// import (
// 	"database/sql"
// 	_ "github.com/lib/pq"
// 	"fmt"
// 	"time"
// )

// type DataBaseProps struct {
// 	Database string
// 	Host string
// 	Port string
// 	User string
// 	Password string
// 	Connection *sql.DB
// }

// func (db *DataBaseProps) connString () string {
// 	return fmt.Sprintf("host=%s port=%s user=%s password=%s dbname=%s sslmode=disable", db.Host, db.Port, db.User, db.Password, db.Database)
// }

// func (db *DataBaseProps) ConnectToDB () error {
// 	var databaseConnectionError error

// 	db.Connection, databaseConnectionError = sql.Open("postgres", db.connString())

// 	if databaseConnectionError != nil {
// 		fmt.Printf("During connection, error has been aquired: %v\n", databaseConnectionError)
// 		return databaseConnectionError
// 	}

// 	if err := db.Connection.Ping(); err != nil {
// 		fmt.Printf("During pinging the database %s, error has been aquired: %v\n", db.Database, err)
// 		return err
// 	}

// 	fmt.Printf("Database connection was succesfull\nError: %v\n", databaseConnectionError)
// 	return nil
// }

// func (db *DataBaseProps) INSERT_INTO (args ...interface{}) error {
// 	if db.Connection == nil {
// 		var err error = fmt.Errorf("No database connection")
// 		fmt.Println(err)
// 		return err
// 	}

// 	var err error
// 	for _, arg := range args {
// 		var query string = fmt.Sprint("INSERT INTO passwords (passwordOfUser, dateOfInsert) VALUES ($1, $2)")
// 		_, err = db.Connection.Exec(query, arg, time.Now().Format("2006-01-02"))
// 		if err != nil {
// 			fmt.Printf("During completing the query, error has been aquired: %v\n", err)
// 			return err
// 		}
// 	}

// 	fmt.Printf("Password was inserted: %s\n", args...)
// 	return nil
// }

// func (db *DataBaseProps) CloseTheDB () error {
// 	var err error = db.Connection.Close()
// 	if err != nil {
// 		fmt.Printf("During closing, error has been aquired: %v\n", err)
// 	}

// 	fmt.Printf("Database %s has been successfully closed.", db.Database)
// 	return err
// }

// func main () {
// 	var database DataBaseProps = DataBaseProps{
// 		Database: "postgres",
// 		Host: "localhost",
// 		Port: "5432",
// 		User: "postgres",
// 		Password: "",
// 	}

// 	database.ConnectToDB()	

// 	defer database.CloseTheDB()
// }

package main

import (
	"fmt"
	"os"
	"bufio"
)

type TextFile struct {
	fileName string
	fileObject *os.File
}

func CreateTextFileStruct (name string) (TextFile, error) {
	var file *os.File
	var errOfCreating error

	if _, err := os.Stat(name); os.IsNotExist(err) {
		file, errOfCreating = os.Create(name)
	} else {
		file, errOfCreating = os.OpenFile(name, os.O_APPEND|os.O_WRONLY, 0644)
	}

	if errOfCreating != nil {
		fmt.Printf("Error has been aquired during opening or creating the file: %v\n", errOfCreating)
		return TextFile{}, errOfCreating
	}

	return TextFile{
		fileName:   name,
		fileObject: file,
	}, nil
}


func (this *TextFile) closeTheFile () error {
	err := this.fileObject.Close()
	if err != nil {
		fmt.Printf("Error has been aquired during closing: %v\n", err)
		return err
	}

	fmt.Printf("File has been successfully closed\n")
	return nil
}

func (this *TextFile) goRoutineFunc (channelForGo chan []byte) {
	for {
		value := <- channelForGo
		err := this.writeToFile(value)
		if err != nil {
			fmt.Printf("Error writing to file: %v\n", err)
		}
	}
}

func (this *TextFile) writeToFile (buffer []byte) error { // to write into file
	if buffer == nil {
		return fmt.Errorf("BUFFER IS EMPTY(	((((((((())))))))))")
	}

	if _, err := this.fileObject.Write(buffer); err != nil {
		return err
	}

	return nil
}

func main () {
	var channelForGo chan []byte = make(chan []byte)
	TextFileStruct, err := CreateTextFileStruct("text.txt")
	if err != nil {
		fmt.Printf("Error has been aquired: %v", err)
		return
	}
	defer TextFileStruct.closeTheFile()
	
	go TextFileStruct.goRoutineFunc(channelForGo)

	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Text your input:")
	for  {
		input, err := reader.ReadString('\n')
		if err != nil {
			fmt.Printf("Error has been aquired: %v", err)
			return
		}

		if input == "exit\n" {
			close(channelForGo)
			return
		}

		channelForGo <- []byte(input)
	}
}