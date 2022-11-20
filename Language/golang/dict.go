package main

import "fmt"

func main() {
	m := make(map[string]int64)
	m["shohag"] = 44
	m["kabir"] = 44

	fmt.Println(len(m))

	for key, value := range m { // care index
		fmt.Println(key, value)
	}

	for _, element := range m { // don't care index
		fmt.Println(element)
	}
}
