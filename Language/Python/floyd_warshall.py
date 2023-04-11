from typing import List

class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        dist = [[float("inf") for i in range(N)] for j in range(N)]
        for i in range(N):
            dist[i][i] = 0
        for u,v,w in times:
            dist[u-1][v-1] = w
        for k in range(N):
            for i in range(N):
                for j in range(N):
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j])
        if max(dist[K-1]) < float("inf"):
            return max(dist[K-1])
        else:
            return -1