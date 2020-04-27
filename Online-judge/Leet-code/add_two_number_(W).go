
var root *ListNode

func getNumber(list *ListNode) int {
	if list.Val == 0 {
		return 0
	}
	var number int = 0
	var currentNode *ListNode = list
	for currentNode.Next != nil {
		number *= 10
		number += currentNode.Val
		currentNode = currentNode.Next
	}
	number *= 10
	number += currentNode.Val
	return number
}

func addNode(Value int) {
	var currentNode *ListNode
	currentNode = root
	var newNode ListNode
	newNode.Val = Value
	newNode.Next = nil
	if root == nil {
		root = &newNode
	} else {
		for currentNode.Next != nil {
			currentNode = currentNode.Next
		}
		currentNode.Next = &newNode
	}
}

func reverse(list *ListNode) *ListNode {
	var currentNode *ListNode = list
	var previousNode *ListNode = nil
	var nextNode *ListNode = nil
	for currentNode.Next != nil {
		nextNode = currentNode.Next
		currentNode.Next = previousNode
		previousNode = currentNode
		currentNode = nextNode
	}
	currentNode.Next = previousNode
	previousNode = currentNode
	return previousNode
}

func newNodePrepare(Val int) *ListNode {
	if Val == 0 {
		var newNode ListNode
		newNode.Val = 0
		newNode.Next = nil
		root = &newNode
		return root
	}
	for Val != 0 {
		var remainder int
		remainder = Val % 10
		addNode(remainder)
		Val /= 10
	}
	return root
}

func addTwoNumbers(list1 *ListNode, list2 *ListNode) *ListNode {
	l1 := reverse(list1)
	l2 := reverse(list2)
	var summation int = (getNumber(l1) + getNumber(l2))
	return newNodePrepare(summation)
}

