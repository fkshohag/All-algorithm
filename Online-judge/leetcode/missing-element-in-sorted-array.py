from typing import List


class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        n = len(nums)

        missingNums = 0
        for i in range(1, n):
            missingNums = nums[i] - nums[i - 1] - 1 # pair missing number count
            if missingNums >= k:
                return nums[i - 1] + k
            k -= missingNums # update found missing number
        return nums[n - 1] + k 