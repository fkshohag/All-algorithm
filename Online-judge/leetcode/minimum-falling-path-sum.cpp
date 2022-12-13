# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-falling-path-sum/description/
 */

/**
 * @brief 
 * Time Complexity: O(N^2)
 * For every cell in the matrix, we will compute the result only once and update the memo. 
 * For the subsequent calls, we are using the stored results that take O(1) time. There are N^2
 * cells in the matrix, and thus N^2
 * dp states. So, the time complexity is O(N^2)
 * 
 * Space Complexity: O(N^2)
 * 
 * The recursive call stack uses O(N)O(N)O(N) space. As the maximum depth of the tree is NNN,
 * we can’t have more than NNN recursive calls on the call stack at any time. The 2D matrix memo uses O(N^2) 
 * space. Thus, the space complexity is O(N) = O(N^2)
 * 
 */
class Solution {
private:
    vector<vector<int>> dp;
    int minSumPath(vector<vector<int>>& matrix, int row, int col) {
        if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix.size()) return INT_MAX;
        if (dp[row][col] != -1) return dp[row][col];
        if (row == matrix.size() - 1) return matrix[row][col];

        int left = minSumPath(matrix, row + 1, col);
        int middle = minSumPath(matrix, row + 1, col + 1);
        int right = minSumPath(matrix, row + 1, col - 1);

        return dp[row][col] = min(left, min(middle, right)) + matrix[row][col];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        dp = vector<vector<int>>(matrix.size(), vector<int>(matrix.size(), -1));
        int minSum  = INT_MAX;
        for (int col = 0; col < matrix.size(); col++) {
            minSum = min(minSum, minSumPath(matrix, 0, col));
        }
        return minSum;
    }
};