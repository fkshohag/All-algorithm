# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/coin-change/description/
 * Time complexity O(n^2)
 * Memory complexity O(n)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // 0 can we construct with 0 
        
        for (int i = 1; i <= amount; i++) {
            for (int k = 0; k < coins.size(); k++) {
                if (coins[k] <= i) {
                    dp[i] = min(dp[i], dp[i-coins[k]]+1);
                }
            }
        }
        if (dp[amount] == amount+1) return -1;
        return dp[amount];
    }
};