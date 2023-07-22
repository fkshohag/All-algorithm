class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        dx = [1, -2, -2, -1, 1, 2, 2, 1]
        dy = [-2, -1, 1, 2, 2, 1, -1, -2]
        dp = [[[0] * n for _ in range(n)] for _ in range(k + 1)]

        dp[0][row][column] = 1

        for move in range(1, k + 1):
            for i in range(n):
                for j in range(n):
                    for d in range(8):
                        xx = i - dx[d]
                        yy = j - dy[d]
                        if 0 <= xx < n and 0 <= yy < n:
                            dp[move][xx][yy] += 0.125 * dp[move - 1][xx][yy]

        total_probability = 0
        for i in range(n):
            for j in range(n):
                total_probability += dp[k][i][j]
        return total_probability