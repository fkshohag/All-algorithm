def duplicate_remove(nums):
	_len = len(nums)
	counter = 1
	for index in range(1,_len):
		if nums[index] != nums[index-1]:
			nums[counter] = nums[index]
			counter += 1
	return counter

print(duplicate_remove([1,2,3,4]))