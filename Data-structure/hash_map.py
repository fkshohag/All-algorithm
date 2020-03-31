class Node:
	def __init__(self, key , value):
		self.key = key
		self.value = value

	def  __eq__(self, other):
		return self.key == other.key

class HasMap:
	def __init__(self):
		self.store = [None for _ in range(16)]
		self.size = 0

	def _hash(self, key):
		if isinstance(key, int):
			return key
		index = 53
		for ch in key:
			index = 33*index+ord(ch)
		return index

	def _get_index(self, key_hash):
		return key_hash % 15

	def map(self, key, value):
		new_node = Node(key, value)
		key_hash = self._hash(key)
		index = self._get_index(key_hash)
		if not self.store[index]:
			self.store[index] = [new_node]
		else:
			list_at_index = self.store[index]
			if new_node not in list_at_index:
				list_at_index.append(new_node)
				self.size += 1
			else:
				for _node in list_at_index:
					if _node == new_node:
						_node.value = value
						break

	def get(self, key):
		key_hash = self._hash(key)
		index = self._get_index(key_hash)
		if not self.store[index]:
			return None
		else:
			list_at_index = self.store[index]
			for node in list_at_index:
				if node.key == key:
					return node.value
			return None


hash = HasMap()
hash.map("shohag", "kabir")
value = hash.get("shohag")
print(value)
