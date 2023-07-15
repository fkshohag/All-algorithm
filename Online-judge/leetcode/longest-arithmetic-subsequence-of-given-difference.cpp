# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
 * time complexity O(n)
 * space complexity O(n)
*/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map<int, int> dp;

        for (int num : arr) {
            dp[num] = dp.count(num - difference) ? dp[num - difference] + 1 : 1;
            ans = max(ans, dp[num]);
        }   
        return ans;
    }
};