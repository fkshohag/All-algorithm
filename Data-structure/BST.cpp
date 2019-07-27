# include <iostream>
# include <cstdio>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};
Node *root = NULL;

Node* insertNode(Node *node, int data) {
    if (node == NULL) {
        node = new Node();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    } else {
        if(data > node->data) {
            node->right = insertNode(node->right, data);
        } else {
            node->left = insertNode(node->left, data);
        }
    }
    return node;
}
void inOrder(Node *node) {
    if(node != NULL) {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

void preOrder(Node *node) {
	if(node != NULL) {
		printf("%d ", node->data);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void postOrder(Node *node) {
	if(node != NULL) {
	    postOrder(node->left);
	    postOrder(node->right);
		printf("%d ", node->data);
	}
	
}

int main() {
	root = insertNode(root, 4);
    root = insertNode(root, 1);
    root = insertNode(root, 34);
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
}
