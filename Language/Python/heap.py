import heapq

# minHeap
min_heap = [45, 5, 6, 1, 2]
heapq.heapify(min_heap)
print(min_heap)


# maxHeap

class MaxHeap:
    def __init__(self, data):
        if data is None:
            self.data = []
        else:
            self.data = [-val for val in data]
            heapq.heapify(self.data)

    def push(self, val):
        heapq.heappush(self.data, -val)

    def pop(self):
        return -heapq.heappop(self.data)

    def top(self):
        return -self.data[0]


mxHeap = MaxHeap([])
mxHeap.push(1)
mxHeap.push(2)
mxHeap.push(67)
mxHeap.push(0)
mxHeap.push(234)
print(mxHeap.pop())
