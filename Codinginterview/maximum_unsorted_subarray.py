def max_unsorted_subarray(arr):
	_len = len(arr)
	start, end = -1, -1
	for index in range(0, _len-1):
		if arr[index] > arr[index+1]:
			start = index
			break;

	if start == -1:
		return -1

	for index in range(_len-1, 0, -1):
		if arr[index] < arr[index-1]:
			end = index
			break

	mn, mx = arr[start], arr[start]

	for index in range(start+1, end+1):
	 	if arr[index] < mn:
	 		mn = arr[index]
	 	elif arr[index] > mx:
	 		mx = arr[index]

	for index in range(0, start):
		if arr[index] > mn:
			start = index

	for index in range(_len-1, end+1, -1):
		if arr[index] < mx:
			end = index

	return (start, end)

_mx_unsorted=max_unsorted_subarray([5,6,1,2,4,7])
print(_mx_unsorted)
