package main

import "fmt"

// Qnode ...
type Qnode struct {
	key, value int
	prev, next *Qnode
}

func addQNode(key int, value int) *Qnode {
	return &Qnode{
		key:   key,
		value: value,
		prev:  nil,
		next:  nil,
	}
}

// Queue ...
type Queue struct {
	front *Qnode
	rear  *Qnode
}

func (q *Queue) isEmpty() bool {
	return q.rear == nil
}

func (q *Queue) addFrontPage(key int, value int) *Qnode {
	page := addQNode(key, value)
	if q.front == nil && q.rear == nil {
		q.front, q.rear = page, page
	} else {
		page.next = q.front
		q.front.prev = page
		q.front = page
	}
	return page
}

func (q *Queue) moveToFront(page *Qnode) {
	if page == q.front {
		return
	} else if page == q.rear {
		q.rear = q.rear.prev
		q.rear.next = nil
	} else {
		page.prev.next = page.next
		page.next.prev = page.prev
	}

	page.next = q.front
	q.front.prev = page
	q.front = page
}

func (q *Queue) removeRear() {
	if q.isEmpty() {
		return
	} else if q.front == q.rear {
		q.front, q.rear = nil, nil
	} else {
		q.rear = q.rear.prev
		q.rear.next = nil
	}
}

func (q *Queue) getRear() *Qnode {
	return q.rear
}

// LRUCache ...
type LRUCache struct {
	capacity, size int
	pageList       Queue
	pageMap        map[int]*Qnode
}

func (lru *LRUCache) initLru(capacity int) {
	lru.capacity = capacity
	lru.pageMap = make(map[int]*Qnode)
}

func (lru *LRUCache) get(key int) int {
	if _, found := lru.pageMap[key]; !found {
		return -1
	}
	val := lru.pageMap[key].value
	lru.pageList.moveToFront(lru.pageMap[key])
	return val
}

func (lru *LRUCache) put(key int, value int) {
	if _, found := lru.pageMap[key]; found {
		lru.pageMap[key].value = value
		lru.pageList.moveToFront(lru.pageMap[key])
		return
	}

	if lru.size == lru.capacity {
		key := lru.pageList.getRear().key
		lru.pageList.removeRear()
		lru.size--
		delete(lru.pageMap, key)
	}
	page := lru.pageList.addFrontPage(key, value)
	lru.size++
	lru.pageMap[key] = page
}

func main() {
	var cache LRUCache
	cache.initLru(2)
	cache.put(2, 2)
	fmt.Println(cache.get(2))
	fmt.Println(cache.get(1))
	cache.put(1, 1)
	cache.put(1, 5)
	fmt.Println(cache.get(1))
	fmt.Println(cache.get(2))
	cache.put(8, 8)
	fmt.Println(cache.get(1))
	fmt.Println(cache.get(8))
}
// Output
// 2
// -1
// 5
// 2
// -1
// 8
