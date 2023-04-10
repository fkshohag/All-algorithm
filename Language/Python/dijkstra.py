from collections import defaultdict
from typing import List
import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = defaultdict(list)
        for u, v, time in times:
            graph[u].append((v, time))
        heap = [(0, k)]
        distance = [0] + [float("inf")] * n
        distance[k] = 0

        while heap:
            utime, node = heapq.heappop(heap)
            for vnode, vtime in graph[node]:
                if utime + vtime < distance[vnode]:
                    distance[vnode] = utime+vtime
                    heapq.heappush(heap, (utime + vtime, vnode))

        if max(distance) < float('inf'):
            return max(distance)
        else:
            return -1