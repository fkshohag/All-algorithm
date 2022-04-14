package main

import "fmt"

func isUnique(str string) bool {
	if len(str) > 128 {
		return false
	}

	var flag [128 + 1]bool
	for index := 0; index < len(str); index++ {
		var key int = int(str[index])
		if flag[key] {
			return false
		}
		flag[key] = true
	}
	return true
}

func main() {
	result := isUnique("h")
	if result {
		fmt.Println("Unique")
	} else {
		fmt.Println("Not unique")
	}
}
