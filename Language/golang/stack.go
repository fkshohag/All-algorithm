package main

const LENGTH = 10000

type Stack struct {
	data [LENGTH]int
	size int
}

func (stack *Stack) setSize(size int) {
	stack.size = size
}

func (stack *Stack) push(value int) {
	if stack.size < LENGTH {
		stack.size += 1
		stack.data[stack.size] = value
	}
}

func (stack *Stack) pop() int {
	if stack.size > 0 {
		stack.size--
	}
	return stack.data[stack.size]
}

func (stack *Stack) getTopValue() int {
	return stack.data[stack.size]
}

func main() {
	stack := Stack{size: 0}
	stack.push(23)
	stack.push(64)
	stack.push(2)
	stack.pop()
	println(stack.getTopValue())
}
