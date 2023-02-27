from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root == None:
            return root
        left: TreeNode = root.left
        right: TreeNode = root.right
        root.left = self.invertTree(right)
        root.right = self.invertTree(left)
        return root