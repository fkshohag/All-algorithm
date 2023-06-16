from math import comb
from typing import List


class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        mod = 10 ** 9 +7

        def dfs(nums: List[int]) -> int:
            if len(nums) <= 2:
                return 1
            leftTree = [val for val in nums if val < nums[0]]
            rightTree = [val for val in nums if val > nums[0]]
            return (comb(len(leftTree) + len(rightTree), len(rightTree)) % mod)* (dfs(leftTree) % mod * dfs(rightTree) % mod) % mod
        return (dfs(nums) - 1) % mod 
