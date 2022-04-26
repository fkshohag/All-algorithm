def max_distance(arr, i, j):
	elements = []

	for index, element in enumerate(arr):
		elements.append((element, index))
	elements.sort()

	_distance = -1
	_min_index = elements[0][1]

	for item in elements:
		old_index = item[1]
		if old_index <= _min_index:
			_min_index = old_index
		else:
			_distance = max(_distance, old_index - _min_index)
	return _distance

x = max_distance([1,3,4,0], 0, 2)
print(x)
