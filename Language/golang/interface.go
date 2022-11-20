package main

import "fmt"

type EmployeeInterface interface {
	setName(name string) string
	getName() string
}

type Employee struct {
	name string
}

type User struct {
	name string
}

func (employee Employee) getName() string {
	return employee.name
}

func (employee Employee) setName(name string) string {
	employee.name = name
	return employee.name
}

func (user User) getName() string {
	return user.name
}

func (user User) setName(name string) string {
	user.name = name
	return user.name
}

func abstra(empInterface EmployeeInterface) {
	fmt.Println(empInterface.getName())
}

func main() {
	em := Employee{name: "shohag"}
	abstra(em)

	user := User{name: "kabir"}
	abstra(user)
}
