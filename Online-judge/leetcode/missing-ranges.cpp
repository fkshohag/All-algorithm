#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/missing-ranges/description/
 * Time complexity: O(n).
 * Space complexity: O(n)
 */

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = (int) nums.size();
        vector<vector<int>> res;
        
        if (n == 0) {
            res.push_back({lower, upper});
            return res;
        }
        // starting index checking
        if (lower < nums[0]) {
            res.push_back({lower, nums[0] - 1});
        }

        for (int index = 0; index < n - 1; index++) {
            if (nums[index + 1] - nums[index] <= 1) continue;
            res.push_back({nums[index] + 1, nums[index + 1] - 1});
        }
        // upper index checking
        if (upper > nums[n - 1]) {
            res.push_back({nums[n - 1] + 1, upper});
        }
        return res;
    }
};