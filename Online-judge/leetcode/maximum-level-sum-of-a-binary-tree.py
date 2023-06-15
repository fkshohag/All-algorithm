# Definition for a binary tree node.
import collections
from typing import Optional

"""
Md.Shohag <shohag.fks@gmail.com>
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
Time complexity O(N)
Space complexity O(n) Tree Hight 2^h = N
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        mx, ans, level = float("-inf"), 0, 0
        q = collections.deque()
        q.append(root)

        while q:
            level += 1
            currentLevelSum = 0
            qsize = len(q)

            for _ in range(qsize):
                top = q.popleft()
                currentLevelSum += top.val
                if top.left:
                    q.append(top.left)
                if top.right:
                    q.append(top.right)
                    
            if currentLevelSum > mx:
                mx = currentLevelSum
                ans = level
        return ans