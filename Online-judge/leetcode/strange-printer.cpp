# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/strange-printer/description/
 * Time complexity O(n^3)
 * Space complexity O(n^2)
*/

class Solution {
private:
    vector<vector<int>> dp;
    int n;
    string s;

    int solve(int left, int right) {
        if (left == right) return 1;
        if (dp[left][right] != -1) return dp[left][right];

        int minimumOperation = INT_MAX;
        for (int k = left; k < right; k++) {
            minimumOperation = min(minimumOperation, solve(left, k) + solve(k + 1, right));
        }
        return dp[left][right] = (s[left] == s[right]) ? minimumOperation - 1 : minimumOperation;

    }
    
public:
    int strangePrinter(string str) {
        n = str.size();
        s = str;
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};
