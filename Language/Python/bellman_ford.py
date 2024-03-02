from typing import List


class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        dist = [0] + [float("inf")] * N
        dist[K] = 0
        for node in range(1, N):
            for u, v, w in times:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
        if max(dist) < float("inf"):
            return max(dist)
        else:
            return -1
