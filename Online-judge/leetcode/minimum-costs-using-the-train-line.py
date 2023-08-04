from typing import List


class Solution:
    def minimumCosts(self, regular: List[int], express: List[int], expressCost: int) -> List[int]:
        N = len(regular) + 1
        dp = [[0]* 2 for _ in range(N)]
        dp[0][1] = 0
        dp[0][0] = expressCost

        ans = []

        for i in range(1, N):
            dp[i][1] = regular[i - 1] + min(dp[i - 1][1], dp[i - 1][0])
            dp[i][0] = express[i - 1] +  min(expressCost + dp[i - 1][1], dp[i - 1][0])
            ans.append(min(dp[i][1], dp[i][0]))
        return ans