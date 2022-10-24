# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * https://leetcode.com/problems/target-sum
 * Running Complexity O(t.n) t refer the sum of the nums and n refers the lengthof nums
 * Space Complexity: O(t.n)
 */


class Solution {
private:
    vector<vector<int>> memo;
    int total;
    
    int summation(vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
        }
        return s;
    }
    
    int way(vector<int>& nums, int i, int sum, int target) {
        if (i == nums.size()) {
            if (sum == target) return 1;
            else return 0;
        }
        if (memo[i][sum + total] != -1) return memo[i][sum + total];
        
        int add = way(nums, i + 1, sum + nums[i], target);
        int substract = way(nums, i + 1, sum - nums[i], target);
        memo[i][sum + total] = add + substract;
        return memo[i][sum + total];
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        total = summation(nums);
        memo = vector<vector<int>>(nums.size(), vector<int>(2 * total + 1, -1));
        return way(nums, 0, 0, target);
    }
};