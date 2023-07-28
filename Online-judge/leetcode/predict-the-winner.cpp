#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/predict-the-winner/editorial/
 * Time complexity: O(N^2).
 * Space complexity: O(N^2).
 */

class Solution {
private:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int left, int right) {
        if (dp[left][right] != -1) return dp[left][right];
        if (left == right) {
            return nums[left];
        }
        int leftScore = nums[left] - solve(nums, left + 1, right);
        int rightScore = nums[right] - solve(nums, left, right - 1);

        dp[left][right] = max(leftScore, rightScore);
        return dp[left][right];
    }
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};