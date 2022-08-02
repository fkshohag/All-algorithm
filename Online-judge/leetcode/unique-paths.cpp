# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/unique-paths/
 */

class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& dp, int &m, int &n) {
        if (i == m-1 || j == n-1) return 1;
        else if (dp[i][j] != 0) return dp[i][j];
        return solve(i + 1, j, dp, m, n) + solve(i, j + 1, dp, m, n);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return solve(0, 0, dp, m, n);
    }
};