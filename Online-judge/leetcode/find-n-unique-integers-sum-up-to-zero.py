from collections import defaultdict
from typing import List
"""
Md.Shohag <shohag.fks@gmail.com>
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/
Time complexity O(sqrt(N))
Space complexity O(n) for output
"""

class Solution:
    def sumZero(self, n: int) -> List[int]:
        ans = []
        if n % 2 != 0:
            ans.append(0)
        for i in range(1, (n // 2) + 1):
            ans.append(i)
            ans.append(i * -1)
        return ans