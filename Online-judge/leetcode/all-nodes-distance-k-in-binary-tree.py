# Definition for a binary tree node.
from collections import defaultdict
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        graph = defaultdict(list)

        def buildGraph(curr, parent):
            if curr and parent:
                graph[curr.val].append(parent.val)
                graph[parent.val].append(curr.val)
            if curr and curr.left:
                buildGraph(curr.left, curr)
            if curr and curr.right:
                buildGraph(curr.right, curr)
        buildGraph(root, None)

        ans = []
        visited = set([target.val])
        def dfs(node, distance):
            if distance == k:
                ans.append(node)
                return
            for child in graph[node]:
                if child not in visited:
                    visited.add(child)
                    dfs(child, distance + 1)
        dfs(target.val, 0)
        return ans
