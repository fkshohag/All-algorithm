class Solution(object):
    def singleNumber(self, nums):
    	nums_dist = {};
    	exact_twice = []
        for num in nums:
        	if num not in nums_dist:
        	 	nums_dist[num] = 1
        	else:
        		nums_dist[num] += 1

        for index, value in nums_dist.items():
        	if value == 1:
        		exact_twice.append(index)
        return exact_twice
