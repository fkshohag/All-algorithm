from collections import defaultdict
from queue import Queue

graph = defaultdict(list)
graph[0].append(1)
graph[1].append(2)
graph[1].append(3)
graph[3].append(4)

visited = [False]*5
distance = [float('inf')]*5
q = Queue()
q.put(0)
visited[0] = True
distance[0] = 0

while not q.empty():
    u = q.get()
    for v in graph[u]:
        if not visited[v]:
            visited[v] = True
            q.put(v)
            distance[v] = distance[u] + 1
print(visited)
print(distance)
