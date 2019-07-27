class SegmentTree(object):
	def __init__(self, data):
		self.data = data
		self.tree = [0]*len(data)*4
		self.treeInit(1, 1, 8)

	def treeInit(self, node, left, right):
		if left == right:
			self.tree[node] = self.data[left]
			return 
		_left = node*2
		_right = node*2+1
		mid = (int)(left+right)/2
		self.treeInit(_left, left, mid)
		self.treeInit(_right, mid+1, right)
		self.tree[node] = self.tree[_left]+self.tree[_right]

	def query(self, node, left, right, i, j):
		if i > right or j < left:
			return 0
		elif left >= i and right <= j:
			return self.tree[node]
		_left = node*2
		_right = node*2+1
		mid = (int)(left+right)/2
		p1 = self.query(_left, left, mid, i, j)
		p2 = self.query(_right, mid+1, right, i, j)
		return p1+p2

	def update(self, node, left, right, i, j, val):
		if i > right or j < left:
			return 
		elif left >= i and right <= j:
			self.tree[node] = val
			return 
		_left = node*2
		_right = node*2+1
		mid = (int)(left+right)/2
		self.update(_left, left, mid, i, j, val)
		self.update(_right, mid+1, right, i, j, val)
		self.tree[node] = self.tree[_left]+self.tree[_right]


if __name__ == '__main__':
	s = SegmentTree([0,1,2,3,4,5,6,7,8])
	s.update(1,1,8,1,1,10)
	print(s.query(1,1,8,1,3))
