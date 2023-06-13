from typing import List

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        i, n = 0, len(nums)
        ranges = []
        while i < n:
            start = nums[i]
            while i + 1 < n and nums[i] + 1 == nums[i + 1]:
                i += 1
            if start == nums[i]:
                 ranges.append(str(start))
            else:
                ranges.append(str(start) + "->" + str(nums[i]))
            i += 1
        return ranges