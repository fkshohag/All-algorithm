from typing import List

'''
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/k-radius-subarray-averages/description/
 * Time complexity: O(n).
 * Space complexity: O(n)
'''



class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if k == 0:
            return nums
        averages = [-1]* n

        if n < (2 * k + 1):
            return averages

        windowSum = sum(nums[: 2 * k + 1])
        averages[k] = windowSum // (2 * k + 1)
        
        for i in range(2 * k + 1, n):
            windowSum = windowSum - nums[i - (2 * k + 1)] + nums[i]
            averages[i - k] = windowSum // (2 * k + 1)
        return averages