class MergeSort:
	def merge_sort(self, data):
		if len(data) > 1:
			mid = len(data) // 2
			left = self.merge_sort(data[:mid])
			right = self.merge_sort(data[mid:])
			return self.merge(left, right)
		else:
			return data

	def merge(self, left, right):
		i, j = 0, 0
		_list = []
		while i < len(left) and j < len(right):
			if left[i] < right[j]:
				_list.append(left[i])
				i += 1
			else:
				_list.append(right[j])
				j += 1
		while i < len(left):
			_list.append(left[i])
			i += 1
		while j < len(right):
			_list.append(right[j])
			j+= 1
		return _list


s = MergeSort()
l = [0,3,2,1,-2,456]
_lis = s.merge_sort(l)
print(_lis)
