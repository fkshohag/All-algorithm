package main

import "fmt"

func main() {
	message := make(chan string)

	go channel(message)

	msg := <-message
	fmt.Println(msg)
	fmt.Println("Hi' I am main function")

}

func channel(c chan string) {
	c <- "hello message, I am from channel"
	fmt.Println("Hi' its matter of life")
}
