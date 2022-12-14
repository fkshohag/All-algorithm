# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/house-robber-ii/description/
 * Time complexity : O(N) where N is the size of nums. We are accumulating results as we are scanning nums.
 * Space complexity : O(1) since we are not consuming additional space 
 * other than variables for two previous results 
 * and a temporary variable to hold one of the previous results.
*/



class Solution {
private:
    int solve(vector<int>& nums, int start, int end) {
        int prev = 0, curr = 0;
        for (int i = start ; i <= end; i++) {
            int temp = curr;
            curr = max(nums[i] + prev, curr);
            prev = temp;
        }
        return curr;
    }
    
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int mx1 = solve(nums, 0, nums.size() - 2);
        int mx2 = solve(nums, 1, nums.size() - 1);
        return max(mx1, mx2);
    }
};