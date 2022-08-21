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

int findKthLast(Node* head, int k) {
	if (head == nullptr) {
		return 0;
	}
	int index = findKthLast(head->next, k) + 1;
	if (index == k) {
		printf("data: %d\n", head->data);
	}
	return index;
}

int main() {
	Node* node2 = new Node(9);
	Node* node1 = new Node(8, node2);
	Node* node = new Node(7, node1);
	int index = findKthLast(node, 1);
	printf("index: %d\n", index);
}