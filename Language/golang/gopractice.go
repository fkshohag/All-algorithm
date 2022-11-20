package practice

import "fmt"

func helloWorld(x, y string) (string, string) {
	fmt.Println(x, y)
	return x, y
}

func swapValue(x *int, y *int) {
	temp := *x
	*x = *y
	*y = temp
}

func arrayManipulation() {
	var data [10][10]int64
	data[0][0] = 44
	println(data[0][0])
}

type Book struct {
	title   string
	author  string
	subject string
	book_id int
}

type React struct {
	height, weight int
}

func (react *React) area(value int) int {
	return react.height * react.weight * value
}

func printBook(book Book) {
	fmt.Println(book.title)
	fmt.Println(book.author)
	fmt.Println(book.subject)
	fmt.Println(book.subject)
	fmt.Println(book.book_id)
}

func main() {
	// arrayManipulation()
	//

	// Structure
	// var books1 Book
	// books1.title = "Go programming"
	// books1.author = "Shohag"
	// books1.subject = "Programming"
	// books1.book_id = 34

	// printBook(books1)

	// method with structure
	// r := React{weight: 34, height: 4}

	// fmt.Println("area ", r.area(5))

	// a, b := helloWorld("Hello", "world")
	// println(a, b)

	// x := 1
	// k, e := 3, 4
	// swapValue(&k, &e)
	// println(k, e)

	// const LENGTH int32 = 34
	// for index := x; index < int(LENGTH); index++ {
	// 	fmt.Printf("%d ", index)
	// }
}
