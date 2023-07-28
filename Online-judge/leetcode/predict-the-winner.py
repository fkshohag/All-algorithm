from typing import List


class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [[0] * n for _ in range(n)]

        for index in range(n):
            dp[index][index] = nums[index] 

        for index in range(1, n):
            for left in range(n - index):
                right = left + index
                dp[left][right] = max(nums[left] - dp[left + 1][right], nums[right] - dp[left][right - 1])
                
        return dp[0][n - 1] >= 0