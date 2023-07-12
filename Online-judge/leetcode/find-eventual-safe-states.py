from collections import defaultdict, deque
from typing import List


class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        indegree = [0] * n
        adj = defaultdict(list)

        for i in range(n):
            for node in graph[i]:
                adj[node].append(i) # node -> i
                indegree[i] += 1

        q = deque()
        for index  in range(n):
            if indegree[index] == 0:
                q.append(index)

        while q:
            node = q.popleft()
            for child in adj[node]:
                indegree[child] -= 1
                if indegree[child] == 0:
                    q.append(child)
        
        safeNodes = []
        for i in range(n):
            if not indegree[i]:
                safeNodes.append(i)
        return safeNodes
