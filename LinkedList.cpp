# include <stdio.h>
struct Node {
    int data;
    Node *next;
};
Node *root = NULL;

void rightPush(int data)
{
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->next = NULL;
    } else {
        Node *currentNode = root;
        while(currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        currentNode->next = newNode;
    }
}

void leftPush(int data)
{
    if(root == NULL) {
        root = new Node();
        root->data = data;
        root->next = NULL;
    } else {
        Node *currentRoot = root;
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = currentRoot;
        root = newNode;
    }
}

void popLeft()
{
    if (root != NULL && root->next == NULL) {
        Node *temp = root;
        root = root->next;
        delete(temp);
    } else if(root != NULL && root->next != NULL) {
        Node *currentRoot = root;
        root = currentRoot->next;
        delete(currentRoot);
    }
}

void popRight()
{
    if(root != NULL && root->next == NULL) {
        Node *temp = root;
        root = root->next;
        delete(temp);
    } else if(root != NULL && root->next != NULL) {
        Node *currentNode = root;
        Node *previousNode = NULL;
        while(currentNode->next != NULL) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        delete(currentNode);
        previousNode->next = NULL;
    }
}

void pop(int data)
{
    if (root->data == data) {
        if(root->next == NULL) {
            Node *temp = root;
            root = root->next;
            delete(temp);
        } else {
            Node *currentNode = root;
            root = root->next;
            delete(currentNode);
        }
    } else if (root != NULL) {
        Node *currentNode = root;
        Node *previousNode = NULL;
        while(currentNode->data != data) {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        previousNode->next = currentNode->next;
        delete(currentNode);
    }
}

void print()
{
    Node *currentNode = root;
    while(currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}

int main()
{
    rightPush(34);
    rightPush(2);
    rightPush(4);
    leftPush(23);
    pop(4);
    print();
    return 0;
}
