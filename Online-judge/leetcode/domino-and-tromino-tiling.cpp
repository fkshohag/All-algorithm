#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/domino-and-tromino-tiling/description/
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 * Pattern  n = 2 * (n-1) + (n-3)
 */

const int MOD = 1e9 + 7;
typedef long long int ll;

class Solution {
public:
    int numTilings(int n) {
        vector<ll> dp(1000+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        if (n < 4) return dp[n];
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
        }
        return dp[n];
    }
};