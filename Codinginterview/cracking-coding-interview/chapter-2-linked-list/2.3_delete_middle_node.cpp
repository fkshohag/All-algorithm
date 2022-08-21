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
	Node* next;
	Node(): data(0), next(nullptr) {}
	Node(int x): data(x), next(nullptr) {}
	Node(int x, Node* nextPtr): data(x), next(nextPtr) {}
};

bool deleteMiddleNode(Node* head, int k) {
	if (head == nullptr || head->next == nullptr) return 0;

	while (head->next) {
		if (head->next->data == k) {
			head->next = head->next->next;
			break;
		}
		else {
			head = head->next;
		}
	}
	return true;
}


void printNode(Node* root) {
	Node* currentNode = root;

	while(currentNode != nullptr) {
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
}



int main() {
	Node* node2 = new Node(9);
	Node* node1 = new Node(8, node2);
	Node* node = new Node(7, node1);
	deleteMiddleNode(node, 8);
	printNode(node);
}