# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * https://leetcode.com/problems/climbing-stairs/
 * Running Complexity O(N), 
 * Space Complexity: O(N)
 */


class Solution {
    vector<int>dp;
private:
    int way(int i, int n) {
        if (i == n) return 1;
        if (i > n) return 0;
        if (dp[i] != -1) return dp[i];
        dp[i] = way(i + 1, n) + way(i + 2, n);
        return dp[i];
    }
public:
    int climbStairs(int n) {
        dp = vector<int>(n, -1);
        return way(0, n);
    }
};
