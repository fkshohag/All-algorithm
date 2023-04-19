from typing import Optional

'''
@author Md.Shohag <shohag.fks@gmail.com>
Problem : https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

@brief 
Time complexity : O((n))
Space complexity: O(n)
'''

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], direction: int, steps: int) -> int:
        if node:
            self.longestPath = max(self.longestPath, steps)
            if direction == self.left:
                self.dfs(node.left, self.right, steps + 1)
                self.dfs(node.right, self.left, 1)
            else:
                self.dfs(node.right, self.left, steps + 1)
                self.dfs(node.left, self.right, 1)
        

    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.left = 1
        self.right = 2
        self.longestPath = 0
        self.dfs(root, self.left, 0)
        self.dfs(root, self.right, 0)
        return self.longestPath