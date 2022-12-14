# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/house-robber/description/
 */

/**
 * @brief 
 * Time Complexity: O(N) since we process at most NNN recursive calls, 
 * thanks to caching, and during each of these calls, we make an O(1) computation which is simply making two other recursive calls, 
 * finding their maximum, and populating the cache based on that.
 * Space Complexity: O(N) which is occupied by the cache and also by the recursion stack.
 * 
 */

class Solution {
private:
    int solve(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size()) return 0;
        if (dp[index] != -1) return dp[index];
        return dp[index] = max(solve(nums, index + 1, dp), solve(nums, index + 2, dp) + nums[index]);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};