package main

import "fmt"

const INSERT_TYPE = "insert"
const REMOVE_TYPE = "remove"

func oneEditReplace(s1 string, s2 string) bool {
	foundDiff := false
	for index := 0; index < len(s1); index++ {
		if s1[index] != s2[index] {
			if foundDiff {
				return false
			}
			foundDiff = true
		}
	}
	return true
}

func oneEditInsertAndRemove(s1 string, s2 string, operationType string) bool {
	firstStringIndex := 0
	secondStringIndex := 0
	for firstStringIndex < len(s1) && secondStringIndex < len(s2) {
		if s1[firstStringIndex] != s2[secondStringIndex] {
			if firstStringIndex != secondStringIndex {
				return false
			}
			if operationType == INSERT_TYPE {
				firstStringIndex++
			} else if operationType == REMOVE_TYPE {
				secondStringIndex++
			}
		} else {
			firstStringIndex++
			secondStringIndex++
		}
	}
	return true
}

func oneEditAway(s1 string, s2 string) bool {
	if len(s1) == len(s2) {
		return oneEditReplace(s1, s2)
	} else if len(s1)+1 == len(s2) {
		return oneEditInsertAndRemove(s1, s2, REMOVE_TYPE)
	} else if len(s1)-1 == len(s2) {
		return oneEditInsertAndRemove(s1, s2, INSERT_TYPE)
	}
	return false
}

func main() {
	result := oneEditAway("pale", "ple")
	fmt.Println(result)
}
