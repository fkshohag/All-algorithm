package main

import "fmt"

func urLify(str []rune, size int) string {
	spaceCouter, index := 0, 0
	for i := 0; i < size; i++ {
		if str[i] == ' ' {
			spaceCouter++
		}
	}

	index = size + spaceCouter*2
	lastIndex := index
	if size < len(str) {
		str[size] = '\n'
	}

	for i := size - 1; i >= 0; i-- {
		if str[i] == ' ' {
			str[index-1] = '0'
			str[index-2] = '2'
			str[index-3] = '%'
			index = index - 3
		} else {
			str[index-1] = str[i]
			index = index - 1
		}
	}

	s := string((str[0:lastIndex]))
	return s
}

func getLen(str []rune) int {
	size := 0
	for index := 0; index < len(str); index++ {
		if str[index] != 0 {
			size++
			continue
		} else {
			break
		}
	}
	return size
}

func main() {
	var str = [100]rune{'i', ' ', 'l', 'o', 'v', 'e', ' ', 'b', 'a', 'n', 'g', 'l', 'a', 'd', 'e', 's', 'h'}
	len := getLen(str[:])
	s := urLify(str[:], len)
	fmt.Println(s)
}
