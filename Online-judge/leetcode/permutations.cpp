# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/permutations/description/
 * Time complexity  n! * n
 * Space complexity O(n)
*/

class Solution {
private:
    void solve(int start, vector<int>& nums, vector<vector<int>>& ans) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int index = start; index < nums.size(); index++) {
            swap(nums[start], nums[index]);
            solve(start+1, nums, ans);
            swap(nums[start], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};