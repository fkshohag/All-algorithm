package main

import "fmt"

func main() {
	var data [10]int64 // 1D array
	a := [1][3]int{    // 2D array
		{1, 3, 4},
	}
	var b [2][2]int
	c := [100]int{34, 45}

	fmt.Println(data)
	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)

	// slice
	fmt.Println(data[2:4]) // 2 number index to 4th index
}
