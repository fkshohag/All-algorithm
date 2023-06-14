from typing import Optional

"""
Md.Shohag <shohag.fks@gmail.com>
https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
Time complexity O(N)
Space complexity O(n)  stack calls
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, node: Optional[TreeNode]) -> None:
        if not node:
            return

        self.dfs(node.left)
        if self.prevNode:
            self.minDiff = min(self.minDiff, node.val - self.prevNode.val)

        self.prevNode = node
        self.dfs(node.right)

    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.prevNode = None
        self.minDiff = float("inf")
        self.dfs(root)
        return self.minDiff