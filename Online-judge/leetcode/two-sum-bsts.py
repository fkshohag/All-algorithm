from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

"""
Md.Shohag <shohag.fks@gmail.com>
problem: https://leetcode.com/problems/two-sum-bsts/description/
Time complexity O(m.logn)
Space complexity O(logm+longn)
"""
        
class Solution:
    def twoSumBSTs(self, root1: Optional[TreeNode], root2: Optional[TreeNode], target: int) -> bool:
        def binarySearch(node2, target2):
            if not node2:
                return False
            if node2.val == target2:
                return True
            elif node2.val > target2:
                return binarySearch(node2.left, target2)
            else:
                return binarySearch(node2.right, target2)
        
        def dfs(root, target):
            if not root:
                return False
            if binarySearch(root2, target - root.val):
                return True
            return dfs(root.left, target) or dfs(root.right, target)

        return dfs(root1, target)
