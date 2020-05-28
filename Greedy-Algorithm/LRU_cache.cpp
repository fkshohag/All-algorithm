# include <iostream>
# include <cstdio>
# include <map>
using namespace std;

class QNode {
public:
	int key, value;
	QNode *prev, *next;
	QNode(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
};

class Queue {
	QNode *front , *rear;

	bool isEmpty() {
		return rear == NULL;
	}

public:
	Queue(): front(NULL), rear(NULL) {}

	QNode* front_add(int key, int value) {
		QNode *page = new QNode(key, value);
		if(!front && !rear) {
			front = rear = page;
		} else {
			page->next = front;
			front->prev = page;
			front = page;
		}
		return page;
	}

	void move_to_front(QNode *page) {
		if(page == front) return;
		else if(page == rear) {
			rear = rear->prev;
			rear->next = NULL;
		} else {
			page->prev->next = page->next;
			page->next->prev = page->prev;
		}

		page->next = front;
		front->prev = NULL;
		front->prev = page;
		front = page;
	}

	void remove_rear() {
		if(isEmpty()) return;
		else if(front == rear) {
			delete rear;
			front = rear = NULL;
		} else {
			QNode *temp = rear;
			rear = rear->prev;
			rear->next = NULL;
			delete temp;
		}
	}

	QNode* get_rear() {
		return rear;
	}
};

class LRUCache {
	int capacity, size;
	Queue *pageList;
	map<int, QNode*> pageMap;
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		size = 0;
		pageList = new Queue();
		pageMap = map<int, QNode*>();
	}

	int get(int key) {
		if(pageMap.find(key) == pageMap.end()) {
			return -1;
		}
		int val = pageMap[key]->value;
		pageList->move_to_front(pageMap[key]);
		return val;
	}

	void put(int key, int value) {
		if(pageMap.find(key) != pageMap.end()) {
			pageMap[key]->value = value;
			pageList->move_to_front(pageMap[key]);
			return;
		}

		if(size == capacity) {
			int k = pageList->get_rear()->key;
			pageMap.erase(k);
			pageList->remove_rear();
			size--;
		}

		QNode *page = pageList->front_add(key, value);
		size++;
		pageMap[key] = page;
	}

	~LRUCache() {
		map<int, QNode*>::iterator i1;
		for(i1 = pageMap.begin(); i1 != pageMap.end(); i1++) {
			delete i1->second;
		}
		delete pageList;
	}
};

int main() {
	LRUCache cache(2); 
	// cache capacity 2
	cache.put(2,2);
	cout << cache.get(2) << endl;
	cout << cache.get(1) << endl;
	cache.put(1,1);
	cache.put(1,5);
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
	cache.put(8,8);
	cout << cache.get(1) << endl;
	cout << cache.get(8) << endl;
}

/*
Output

2
-1
5
2
-1
8

*/
