import collections

'''
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/detonate-the-maximum-bombs/
 * Time complexity: O(n^3).
 * Space complexity: O(n^2)
'''

class Solution(object):
    def maximumDetonation(self, bombs):
        graph = collections.defaultdict(list)
        n = len(bombs)

        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                xi, yi, ri = bombs[i]
                xj, yj, _ = bombs[j]

                if ri ** 2 >= (xi - xj) ** 2 + (yi - yj) ** 2:
                    graph[i].append(j)

        def dfs(node, visited):
            visited.add(node)
            for neighbour in graph[node]:
                if neighbour not in visited:
                    dfs(neighbour, visited)
            return len(visited)
        
        ans = 0
        for node in range(n):
            visited = set()
            ans = max(ans, dfs(node, visited))
        return ans