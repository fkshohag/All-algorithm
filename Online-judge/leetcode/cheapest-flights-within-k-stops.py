from collections import defaultdict
from typing import List
from queue import Queue

'''
Bellman ford
Time complexity: O((N + E) . K)
Memory complexity: O(N )
'''
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        dist = [float('inf')] * n
        dist[src] = 0
        for _ in range(k+1):
            temp_dist = dist.copy()
            for u, v, cost in flights:
                if dist[u] != float('inf'):
                    temp_dist[v] = min(temp_dist[v], dist[u] + cost)
            dist = temp_dist
        return dist[dst] if dist[dst] != float('inf') else -1

'''
BFS
Time complexity: O(N + E.K)
Memory complexity: O(N + E.K)
'''
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = defaultdict(list)
        for u, v, cost in flights: graph[u].append((v, cost))

        dist = [float('inf')] * n
        dist[src] = 0
        q = Queue()
        q.put((src, 0))
        stops = 0

        while stops <= k and not q.empty():
            qs = q.qsize()
            while qs:
                node, distance = q.get()
                for neighbour, price in graph[node]:
                    if price + distance <= dist[neighbour]:
                        dist[neighbour] = price + distance
                        q.put((neighbour, dist[neighbour]))
                qs -= 1
            stops += 1

        return dist[dst] if dist[dst] != float('inf') else -1