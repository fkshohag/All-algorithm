from collections import defaultdict, deque
from typing import List


# DFS
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n-1:
            return -1
        networks = defaultdict(list)

        for connection in connections:
            networks[connection[0]].append(connection[1])
            networks[connection[1]].append(connection[0])
        
        def dfs(node, networks, visited):
            visited[node] = True
            for connectedNode in networks[node]:
                if not visited[connectedNode]:
                    dfs(connectedNode, networks, visited)

        disconnectedNetwork = 0
        visited = [False] * n
        for node in range(n):
            if not visited[node]:
                dfs(node, networks, visited)
                disconnectedNetwork += 1
        return disconnectedNetwork - 1
    

# BFS    
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n-1:
            return -1
        networks = defaultdict(list)

        for connection in connections:
            networks[connection[0]].append(connection[1])
            networks[connection[1]].append(connection[0])
        
        def bfs(node, networks, visited):
            visited[node] = True
            q = deque([node])

            while q:
                top = q.popleft()
                for connectedNode in networks[top]:
                    if not visited[connectedNode]:
                        visited[connectedNode] = True
                        q.append(connectedNode)


        disconnectedNetwork = 0
        visited = [False] * n
        for node in range(n):
            if not visited[node]:
                bfs(node, networks, visited)
                disconnectedNetwork += 1
        return disconnectedNetwork - 1


        
        