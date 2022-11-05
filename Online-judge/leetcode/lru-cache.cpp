# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/lru-cache/description/
 * Running complexity O(1)
 * Memory complexity O(n)
*/

class QNode {
    private:
        int key, val;
        QNode *prev, *next;

    public:
        QNode(int k, int v): key(k), val(v), prev(NULL), next(NULL) {} 
        
        QNode* setKey(int k) {
            key = k;
            return this;
        }

        int getKey() {
            return key;
        }

        QNode* setVal(int v) {
            val = v;
            return this;
        }

        int getVal() {
            return val;
        }

        QNode* setPrev(QNode* p) {
            prev = p;
            return this;
        }

        QNode* getPrev() {
            return prev;
        }

        QNode* setNext(QNode* n) {
            next = n;
            return this;
        }

        QNode* getNext() {
            return next;
        }
};

class Queue {
    private:
        QNode *front, *rear;
        bool isEmpty() {
            return rear == NULL;
        }
    public:
        Queue(): front(NULL), rear(NULL) {}

        QNode* push(int key, int val) {
            QNode* newNode = new QNode(key, val);
            if (!front && !rear) {
                front = rear = newNode;
            } else {
                newNode->setNext(front);
                front->setPrev(newNode);
                front = newNode;
            }
            return newNode;
        }

        QNode* moveToFront(QNode* node) {
            if (node == front) {
                return node;
            } else if (node == rear) {
                rear = rear->getPrev();
                rear->setNext(NULL);
            } else {
                node->getPrev()->setNext(node->getNext());
                node->getNext()->setPrev(node->getPrev());
            }
            node->setNext(front);
            front->setPrev(node);
            front = node;
            return front;
        }

        void removeLastNode() {
            if (isEmpty()) return;
            else if (front == rear) {
                delete rear;
                front = rear = NULL;
            } else { 
                QNode* temp = rear;
                rear = rear->getPrev();
                rear->setNext(NULL);
                delete temp; 
            }
        }

        QNode* getRear() {
            return rear;
        }
};

class LRUCache {
private:
    int lruCapacity, size;
    Queue* nodeList;
    map<int, QNode*> nodeMap;

public:
    LRUCache(int capacity) {
        lruCapacity = capacity;
        size = 0;
        nodeList = new Queue();
        nodeMap = map<int, QNode*>();
    }
    
    int get(int key) {
        if (nodeMap.find(key) != nodeMap.end()) {
            QNode* node = nodeMap[key];
            nodeList->moveToFront(node);
            return node->getVal();
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (nodeMap.find(key) != nodeMap.end()) {
            nodeMap[key]->setVal(value);
            nodeList->moveToFront(nodeMap[key]);
            return;
        } else if (size == lruCapacity) {
            QNode* rear = nodeList->getRear();
            nodeMap.erase(rear->getKey());
            nodeList->removeLastNode();
            size--;
        }
        QNode* node = nodeList->push(key, value);
        nodeMap[key] = node;
        size++;
    }
};