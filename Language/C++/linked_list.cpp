# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <map>
# include <unordered_map>
# include<set>

using namespace std;

struct Node {
	int data;
	Node* nextPtr;

	Node() : data(0), nextPtr(nullptr) {}
	Node(int x) : data(x), nextPtr(nullptr) {} 
	Node(int x , Node* ptr) : data(x), nextPtr(ptr) {}
};

// Allow buffer
void deleteDuplicateNodeWithBuffer(Node* root) {
	Node* previous = NULL;
	set<int> hashSet; 

	while(root) {
		if (hashSet.find(root->data) != hashSet.end()) {
			previous->nextPtr = root->nextPtr;
		} else {
			hashSet.insert(root->data);
			previous = root;
		}
		root = root->nextPtr;
	}
}

// Not Allow buffer
void deleteDuplicateNodeWithOutBuffer(Node* root) {
	Node* currentNode = root;
	
	while(currentNode) {
		Node* runnerNode = currentNode;

		while(runnerNode->nextPtr) {
			if (runnerNode->nextPtr->data == currentNode->data) {
				runnerNode->nextPtr = runnerNode->nextPtr->nextPtr;
			} else {
				runnerNode = runnerNode->nextPtr;
			}
		}
		currentNode = currentNode->nextPtr;
	}
}


void printNode(Node* root) {
	Node* currentNode = root;

	while(currentNode != nullptr) {
		cout << currentNode->data << " ";
		currentNode = currentNode->nextPtr;
	}
}


int main() {
	Node* node2 = new Node(4);
	Node* node1 = new Node(4, node2);
	Node* node = new Node(3, node1);
	// deleteDuplicateNodeWithBuffer(node);
	deleteDuplicateNodeWithOutBuffer(node);
	printNode(node);
}