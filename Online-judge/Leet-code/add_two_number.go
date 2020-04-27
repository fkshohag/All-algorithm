func addTwoNumbers(list1 *ListNode, list2 *ListNode) *ListNode {
	var list3 *ListNode
	var node **ListNode = &list3
	var sum int = 0
	for list1 != nil || list2 != nil || sum > 0 {
		if list1 != nil {
			sum += list1.Val
			list1 = list1.Next
		}
		if list2 != nil {
			sum += list2.Val
			list2 = list2.Next
		}
		*node = &ListNode{
			Val:  (sum % 10),
			Next: nil,
		}
		sum /= 10
		node = &((*node).Next)
	}
	return list3
}
