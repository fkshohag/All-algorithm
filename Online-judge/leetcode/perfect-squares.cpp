#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/perfect-squares/description/
 * Running complexity O(n*sqrt(n))
 * Memory complexity O(n)
 */

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for (int number = 1; number <= n; number++) {
            for (int i = 1; i*i <= number; i++) {
                dp[number] = min(dp[number], dp[number - i *i]+1);
            }
        }   
        return dp[n];
    }
};

class Solution {
private:
    int solve(int n, vector<int>& dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        dp[n] = INT_MAX;

        for (int i = 1; i*i <= n; i++) {
            dp[n] = min(dp[n], solve(n-i*i, dp)+1);
        }
        return dp[n];
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        return solve(n, dp);
    }
};