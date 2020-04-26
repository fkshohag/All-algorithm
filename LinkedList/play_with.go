package main

import "fmt"

// Node ...
type Node struct {
	val  int
	Next *Node
}

// LinkedList ...
type LinkedList struct {
	root *Node
}

func (list *LinkedList) addNode(value int) {
	var currentNode *Node
	currentNode = list.root

	newNode := &Node{
		val:  value,
		Next: nil,
	}

	if list.root == nil {
		list.root = newNode
	} else {
		for currentNode.Next != nil {
			currentNode = currentNode.Next
		}
		currentNode.Next = newNode
	}
}

func sumList(list LinkedList) int {
	var sum int = 0
	var currentNode *Node = list.root
	for currentNode.Next != nil {
		sum += currentNode.val
		currentNode = currentNode.Next
	}
	sum += currentNode.val
	return sum
}

func reverse(list LinkedList) LinkedList {
	var currentNode *Node = list.root
	var previousNode *Node = nil
	var nextNode *Node = nil
	for currentNode.Next != nil {
		nextNode = currentNode.Next
		currentNode.Next = previousNode
		previousNode = currentNode
		currentNode = nextNode
	}
	currentNode.Next = previousNode
	previousNode = currentNode
	newList := LinkedList{
		root: previousNode,
	}
	return newList
}

func addTwoNumbers(list1 LinkedList, list2 LinkedList) int {
	l1 := reverse(list1)
	l2 := reverse(list2)
	return sumList(l1) + sumList(l2)
}

func main() {
	var list1 LinkedList
	list1.addNode(2)
	list1.addNode(4)
	var list2 LinkedList
	list2.addNode(2)
	list2.addNode(4)
	x := addTwoNumbers(list1, list2)
	fmt.Printf("%d", x)
}
