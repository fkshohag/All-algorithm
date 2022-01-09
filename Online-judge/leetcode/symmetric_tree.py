class Solution(object):
	def isMirror(self, t1, t2):
		if not t1 and not t2:
			return True
		if not t1 or not t2:
			return False
		return (t1.val == t2.val) and self.isMirror(t1.left, t2.right) and self.isMirror(t1.right, t2.left)

	def isSymmetric(self, root):
		return self.isMirror(root, root)
		
        
