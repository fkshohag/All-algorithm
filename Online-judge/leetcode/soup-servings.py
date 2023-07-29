from collections import defaultdict
from math import ceil

"""
Constant time
"""
class Solution:
    def soupServings(self, n: int) -> float:
        m = ceil(n / 25)
        dp = defaultdict(dict)

        def solve(i: int, j: int) -> float:
            if i <= 0 and j <= 0:
                return 0.5
            if i <= 0:
                return 1.0
            if j <= 0:
                return 0.0
            if i in dp and j in dp[i]:
                return dp[i][j]

            dp[i][j] = (
                solve(i - 4, j) 
                + solve(i - 3, j - 1) 
                + solve(i - 2, j - 2) 
                + solve(i - 1, j - 3)
                ) * 0.25

            return dp[i][j]
        
        for k in range(1, m + 1):
            if solve(k, k) >= 1.0:
                return 1.0
        return solve(m, m)
        
            