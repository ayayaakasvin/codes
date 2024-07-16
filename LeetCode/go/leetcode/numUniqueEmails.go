package leetcode

import (
	"fmt"
	"regexp"
	"strings"
)

func findPlusSign (inputEmail string) bool {
	matched, err := regexp.Match(`\+`, []byte(inputEmail))

	if err != nil {
		return false
	}

	return matched
}

func removeAfterPlusSign (inputEmail string) (string, error) {
	emailParts := strings.Split(inputEmail, "@")
	if len(emailParts) != 2 {
		return "", fmt.Errorf("INVALID FORMAT OF EMAIL")
	}

	localPart, domainPart := emailParts[0], emailParts[1]

	if !findPlusSign(inputEmail) {
		return inputEmail, fmt.Errorf("NO PLUS SIGN IN STRING")
	}

	plusIndex := strings.Index(localPart, "+")
	if plusIndex != -1 {
		localPart = localPart[:plusIndex]
	}

	return localPart + "@" + domainPart, nil
}

func removeDots (inputEmail string) (string, error) {
	email := strings.Split(inputEmail, "@")
	if len(email) != 2 {
		return "", fmt.Errorf("INVALID FORMAT OF EMAIL")
	}

	localPart, domainPart := email[0], email[1]
	localPart = strings.ReplaceAll(localPart, ".", "")

	return localPart + "@" + domainPart, nil
}

func NumUniqueEmails(emails []string) int {
	var mapOfEmails map[string]struct{} = make(map[string]struct{})

	for _, email := range emails {
		var cleanedOne string
		var err error
		cleanedOne, err = removeAfterPlusSign(email)
		if err != nil {
			cleanedOne = email
		}

		result, err := removeDots(cleanedOne)
		if err != nil {
			continue
		}

		mapOfEmails[result] = struct{}{}
	}

	for k, _ := range mapOfEmails {
		fmt.Println(k)
	}

	return len(mapOfEmails)
}