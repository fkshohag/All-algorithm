def max_sum(arr):
	maxSum, CurrentMax = -100000000, 0

	for element in arr:
		CurrentMax += element
		if CurrentMax < 0:
			CurrentMax = 0
		if CurrentMax > maxSum:
			maxSum = CurrentMax
	return maxSum


_list = [-1, -2, 1, 2, 3, -5, 4, 5]
print(max_sum(_list))
		
