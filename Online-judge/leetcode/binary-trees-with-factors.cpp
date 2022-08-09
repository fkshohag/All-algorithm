# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/binary-trees-with-factors/
 * Running Complexity O(n^2), Space Complexity: O(N)O(N)
 */


class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1000000007;
        sort(arr.begin(), arr.end());
        vector<long>dp(arr.size(), 1);
        unordered_map<int, int> mp;
        
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];
                    if (mp.find(right) != mp.end()) {
                        dp[i] = (dp[i] + dp[j] * dp[mp[right]]) % MOD;
                    } 
                }
            }
        }
        
        long ans = 0;
        for (auto x : dp) ans += x;
        return int (ans % MOD);
    }
};