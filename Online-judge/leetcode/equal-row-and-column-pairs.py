from collections import defaultdict
from typing import List
"""
Md.Shohag <shohag.fks@gmail.com>
https://leetcode.com/problems/equal-row-and-column-pairs/description/
Time complexity O(N^2)
Space complexity O(1)
"""

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        row_count = defaultdict(int)
        count = 0

        for row in grid:
            row_count[tuple(row)] += 1

        for col in zip(*grid):
            count += row_count[tuple(col)]
        return count