# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/non-decreasing-subsequences/description/
 * Solution: https://leetcode.com/problems/non-decreasing-subsequences/solutions/3075805/simple-c-recursive-backtracking-with-clear-explanation/
 * Time complexity  O(2^n * n^2)
 * Space complexity O(2^n * n)
*/

class Solution {
private:
    set<vector<int>> res;
    void solve(int index, vector<int>& nums, vector<int>& ans) {
        if (index == nums.size()) {
            if (ans.size() > 1) res.insert(ans);
            return;
        }
        if ((ans.size() && nums[index] >= ans.back()) || !ans.size()) {
            ans.push_back(nums[index]);
            solve(index+1, nums, ans);
            ans.pop_back();
            solve(index+1, nums, ans);
        } else {
            solve(index+1, nums, ans);
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ans;
        solve(0, nums, ans);
        return vector(res.begin(), res.end());
    }
};