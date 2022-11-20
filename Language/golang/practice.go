package main

import (
	"fmt"
)

func main() {
	x := 45
	var y int64 = 45
	var str string = "khohag"
	fmt.Println(len(str))
	fmt.Println(string(str[0]))
	fmt.Println(y)

	if x > 50 {
		fmt.Println("Greater then\n")
	} else if x > 2 && x < 7 {
		fmt.Println("meet the critiria\n")
	} else {
		fmt.Printf("Lesser then\n")
	}
	for i := 0; i < x; i++ {
		fmt.Printf("%d ", i)
	}

	fmt.Println("\n")
	runes := []rune(str)
	fmt.Println(string(runes[0]))

	// Run is 32bit string nothing more
	fmt.Println("\n")

	data := [10]int{34, 45, 4, 56, 4, 5}

	for index, _ := range data {
		fmt.Printf("%d ", data[index])
	}

	dist := make(map[string]int)
	dist["name"] = 34
	for key, value := range dist {
		fmt.Println(key, value)
	}
}
