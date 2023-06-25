from typing import List

class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        MOD = 1000000007
        n = len(locations)

        dp = [[0] * (fuel + 1) for _ in range(n)]

        for f in range(fuel + 1):
            dp[finish][f] = 1

        for f in range(fuel + 1):
            for city in range(n):
                for nextCity in range(n):
                    diff = abs(locations[nextCity] - locations[city])
                    if city != nextCity and f >= diff:
                        dp[city][f] = (dp[city][f] % MOD + dp[nextCity][f - diff] % MOD) % MOD

        return dp[start][fuel]