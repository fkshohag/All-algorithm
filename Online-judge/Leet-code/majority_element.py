class Solution(object):
    def majorityElement(self, nums):
    	nums_dist = {};
    	size = len(nums)
        for num in nums:
        	if num not in nums_dist:
        	 	nums_dist[num] = 1
        	else:
        		nums_dist[num] += 1

        for index, value in nums_dist.items():
        	if value > size // 2:
        		return index
