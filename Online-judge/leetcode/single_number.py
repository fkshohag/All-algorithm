class Solution(object):
    def singleNumber(self, nums):
    	nums_dist = {};
        for num in nums:
        	if num not in nums_dist:
        	 	nums_dist[num] = 1
        	else:
        		nums_dist[num] += 1

        for index, value in nums_dist.items():
        	if value == 1:
        		return index

s = Solution()
k = s.singleNumber([2,3,1,1,2])
print(k)
