# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/unique-paths-ii/
 * time complexity: O(M * N)
 * memory complexity:O(M * N)
 */

class Solution {
private:
    int solve(int i, int j, int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i >= row || j >= col || grid[i][j] == 1) return 0;
        if (i == row - 1 && j == col - 1) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i, j + 1, row, col, grid, dp) + solve(i + 1, j, row, col, grid, dp);
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return solve(0, 0, row, col, obstacleGrid, dp);
    }
};
/*
grid = [
[0, 0, 0],
[0, 1, 0],
[0, 0, 0]
]
dp = [
[2, 1, 1],
[1, -1, 1],
[1, 1, -1]
]
*/