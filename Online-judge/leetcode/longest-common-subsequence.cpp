#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/longest-common-subsequence/description/
 * Time Complexity: O(M*N)
 * Space Complexity: O(M*N)
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.size() + 1][text2.size() + 1];
        memset(dp, 0, sizeof(dp));

        for (int row = text1.size()-1; row >= 0; row--) {
            for (int col = text2.size() - 1; col >= 0; col--) {
                if (text1[row] == text2[col]) {
                    dp[row][col] = 1 + dp[row + 1][col + 1]; // character match that means need to move diagonal
                } else {
                    dp[row][col] = max(dp[row + 1][col], dp[row][col + 1]); // not match take max from right / bottom
                }
            }
        } 
        return dp[0][0];
    }
};