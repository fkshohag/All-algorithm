
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    nodes: List = []
    def dfs(self, root: Optional[TreeNode]):
        if (root == None):
            return
        self.nodes.append(root.val)
        self.dfs(root.left)
        self.dfs(root.right)

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.nodes.clear()
        self.dfs(root)
        self.nodes.sort()
        res: int = 10000000

        for index in range(1, len(self.nodes)):
            if (self.nodes[index] - self.nodes[index-1] < res):
                res = self.nodes[index] - self.nodes[index-1]
        return res