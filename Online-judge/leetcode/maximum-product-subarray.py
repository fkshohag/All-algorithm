'''
Problem: https://leetcode.com/problems/maximum-product-subarray/description/
Time complexity: O(N^2)
Space complexity: O(1)
'''

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) < 1:
            return 0
        result = nums[0]
        for i in range(len(nums)):
            accu = 1
            for j in range(i, len(nums)):
                accu *= nums[j]
                result = max(result, accu)
        return result

'''
Kadane's Algo
Ques : Why do we have a need to traverse from right to left ??
Ans : lets take an example
arr {-8,5,3,1,6}
Time complexity: O(N)
Space complexity: O(1)
'''

from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mx = float("-inf")
        prod = 1

        for num in nums:
            prod *= num
            mx = max(mx, prod)
            if prod == 0:
                prod = 1

        prod = 1
        for index in range(len(nums) - 1, 0, -1):
            prod *= nums[index]
            mx = max(mx, prod)
            if prod == 0:
                prod = 1
        return mx