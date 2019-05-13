class Node(object):
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList(object):
	def __init__(self):
		self.root = None

	def rightPush(self, data):
		if self.root == None:
			self.root = Node(data)
		else:
			currentNode = self.root
			while currentNode.next is not None:
				currentNode = currentNode.next
			newNode = Node(data)
			currentNode.next = newNode

	def leftPush(self, data):
		if self.root == None:
			self.root = Node(data)
		else:
			currentNode = self.root
			newNode = Node(data)
			newNode.next = currentNode
			self.root= newNode

	def rightPop(self):
		if self.root and self.root.next == None:
			temp = self.root
			self.root = self.root.next
			del temp
		elif self.root:
			currentNode = self.root
			previousNode = None
			while currentNode.next is not None:
				previousNode = currentNode
				currentNode = currentNode.next
			del currentNode
			previousNode.next = None

	def leftPop(self):
		if self.root and self.root.next == None:
			temp = self.root
			self.root = self.root.next
			del temp
		elif self.root:
			currentNode = self.root
			self.root = currentNode.next
			del currentNode

	def pop(self, data):
	 	if self.root and self.root.data == data:
	 		self.root = self.root.next
	 	elif self.root:
	 		currentNode = self.root
	 		previousNode = None
	 		while currentNode.data is not data:
	 			previousNode = currentNode
	 			currentNode = currentNode.next
	 		previousNode.next = currentNode.next
	 		del currentNode


	def show(self):
		currentNode = self.root
		while currentNode is not None:
			print(currentNode.data)
			currentNode = currentNode.next

s = LinkedList()
s.rightPush(1)
s.rightPush(2)
s.rightPush(10)
s.rightPush(3)
s.rightPush(3)
s.pop(10)
s.show()

