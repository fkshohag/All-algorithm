#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/subsets/
 * Time complexity : O(N*(2^N))
 * Space complexity : O(N*(2^N))
 */



class Solution {
public:
    vector<vector<int>> ans;
    void solve(int index, vector<int>& nums, vector<int>v) {
        if (index == nums.size()) {
            ans.push_back(v);
            return;
        }
        solve(index + 1, nums, v); // exclude
        v.push_back(nums[index]); // take
        solve(index + 1, nums, v); // next
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums, vector<int> {});
        return ans;
    }
};