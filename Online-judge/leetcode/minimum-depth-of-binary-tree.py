"""
Time complexity: O(n) we tarverse every node
"""

class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def minDepth(self, root):
        if root == None:
            return 0
        elif root.left == None and root.right == None:
            return 1
        min_depth = 100002
        if root.left:
            min_depth = min(self.minDepth(root.left), min_depth)
        if root.right:
            min_depth = min(self.minDepth(root.right), min_depth)
        return min_depth+1
        
# Input: [3,9,20,null,null,15,7]