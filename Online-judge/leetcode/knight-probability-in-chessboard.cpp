# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/knight-probability-in-chessboard/submissions/
 * time complexity: O(k*n^2)
 * memory complexity:O(k*n^2)
 */

class Solution {
private:
    vector<vector<vector<double>>> dp;
    int n;

    double solve(int k, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (k == 0) return 1;
        if (dp[i][j][k] != -1) return dp[i][j][k];

        int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

        double res = 0;
        for (int index = 0; index < 8; index++) {
            int xx = dx[index] + i;
            int yy = dy[index] + j;
            res += 0.125 * solve(k - 1, xx, yy);
        }
        return dp[i][j][k] = res;
    }
    
public:
    double knightProbability(int n, int k, int row, int column) {
        this->n = n;
        dp = vector<vector<vector<double>>> (n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        return solve(k, row, column);
    }
};