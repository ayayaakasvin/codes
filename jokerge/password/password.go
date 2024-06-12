package password

import (
	"fmt"
	"math/rand"
	"strings"
)

type PasswordStruct struct {
	PasswordItself []byte
	Length, currentMissing  int
	UsedSymbolTypes map[string]bool
}

var symbolTypes []string = []string{
	"upper",
	"lower",
	"digit",
	"symbol",
}

var LatinUpperCase []byte = func () []byte {
	var result []byte

	for i := 'A'; i <= 'Z'; i++ {
		result = append(result, byte(i))
	}

	return result
}()

var LatinLowerCase []byte = func () []byte {
	var result []byte

	for i := 'a'; i <= 'z'; i++ {
		result = append(result, byte(i))
	}

	return result
}()

var DigitSet []byte = func () []byte {
	var result []byte

	for i := '0'; i <= '9'; i++ {
		result = append(result, byte(i))
	}

	return result
}()

var SpecialSet []byte = []byte{'@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '!', '~'}

var mapOfSlices map[string][]byte = map[string][]byte{
	"upper" : LatinUpperCase,
	"lower" : LatinLowerCase,
	"digit" : DigitSet,
	"special" :SpecialSet,
}

func (password *PasswordStruct) durakCheck () {
	var typeExistenceCheck bool = false
	for _, typeOf := range symbolTypes {
		typeExistenceCheck = typeExistenceCheck || password.UsedSymbolTypes[typeOf]
	}

	if !typeExistenceCheck {
		fmt.Printf("No symbol chosen, try again...")
		PasswordCreate()
	}
}

func (password *PasswordStruct) shuffleThePassword () {
	rand.Shuffle(len(password.PasswordItself), func(i, j int) {
		password.PasswordItself[i], password.PasswordItself[j] = password.PasswordItself[j], password.PasswordItself[i]
	})
}

func randomChar (typeOf string) byte {
	return mapOfSlices[typeOf][rand.Intn(len(mapOfSlices[typeOf]))]
}

func (password *PasswordStruct) createThePassword () {
	for ; password.currentMissing > 0 ; {
		for _, typeOf := range symbolTypes {
			if password.UsedSymbolTypes[typeOf] {
				var char byte = randomChar(typeOf)
				password.PasswordItself = append(password.PasswordItself, char)
				password.currentMissing--
				if password.currentMissing == 0 {
					break
				}
			}
		}
	}
}

func PasswordCreate() PasswordStruct {

	var lengthOfPassword int
	symbolUseBool := map[string]bool{
		"upper":   false,
		"lower":   false,
		"digit":   false,
		"special": false,
	}

	fmt.Print("Enter the length of password (Not less than 8): ")
	fmt.Scan(&lengthOfPassword)
	for lengthOfPassword < 8 {
		fmt.Print("Invalid input, please try again: ")
		fmt.Scan(&lengthOfPassword)
	}

	PasswordClassForUser := PasswordStruct{
		Length:         lengthOfPassword,
		currentMissing: lengthOfPassword,
		UsedSymbolTypes: symbolUseBool,
	}

	var temp string

	fmt.Print("Will Uppercase Latin be used? [y/n]: ")
	fmt.Scan(&temp)
	if strings.ToLower(temp) == "y" {
		symbolUseBool["upper"] = true
	}

	fmt.Print("Will Lowercase Latin be used? [y/n]: ")
	fmt.Scan(&temp)
	if strings.ToLower(temp) == "y" {
		symbolUseBool["lower"] = true
	}

	fmt.Print("Will Digits be used? [y/n]: ")
	fmt.Scan(&temp)
	if strings.ToLower(temp) == "y" {
		symbolUseBool["digit"] = true
	}

	fmt.Print("Will Special symbols (\"@\", \"#\", etc) be used? [y/n]: ")
	fmt.Scan(&temp)
	if strings.ToLower(temp) == "y" {
		symbolUseBool["special"] = true
	}

	PasswordClassForUser.durakCheck()
	PasswordClassForUser.createThePassword()
	PasswordClassForUser.shuffleThePassword()

	fmt.Printf("Your password: %s\n", string(PasswordClassForUser.PasswordItself))
	return PasswordClassForUser
}