from itertools import groupby
from typing import List
"""
@author Md.Shohag <shohag.fks@gmail.com>
Problem : https://leetcode.com/problems/string-compression/description/
* Time complexity: O(n)
* Space Complexity O(1)
"""

class Solution:
    def compress(self, chars: List[str]) -> int:
        s = ""
        for key, group in groupby(chars):
            count = len(list(group))
            s += key
            if count > 1:
                s += str(count)
        chars[:] = s