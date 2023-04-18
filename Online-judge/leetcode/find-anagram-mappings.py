from collections import defaultdict
from typing import List

class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mapping = defaultdict(int)
        for index, num in enumerate(nums2):
            mapping[num] = index
        ans: List[int] = []
        for num in nums1:
            ans.append(mapping[num])
        return ans