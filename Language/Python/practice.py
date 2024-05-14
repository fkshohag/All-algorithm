data = [1,2,3];
data.append(23)
data.pop(0)

print(data)

from collections import defaultdict
from queue import Queue, PriorityQueue
import heapq

dic = defaultdict(defaultdict)
dic['shohag'] = {
    'name': 'shohag'
}
dic['kabir'] = {
    'name': 'kabir'
}

for key, val in dic.items():
    print(key, val)

q = Queue()
pq = PriorityQueue()
pq.put(20)
pq.put(2)
pq.put(3)
pq.put(1)
print(pq.get())
print(pq.get())


# Heapq

print('heapify start max heap')
d = [1, 2, 3]
d = [-val for val in d]
heapq.heapify(d)
heapq.heappush(d, -10)
print(-heapq.heappop(d))
