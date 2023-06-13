# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/summary-ranges/description/
 */

/**
 * @brief 
 * Time complexity : O(n)
 * Space complexity: O(1) -> ignore input output space
 */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start, i = 0;
        int n = (int) nums.size();
        vector<string> ans;

        while (i < n) {
            start = nums[i];
            while (i + 1 < n && nums[i] + 1 == nums[i+1]) {
                i++;
            }
            if (start == nums[i]) {
                ans.push_back(to_string(nums[i]));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
            i++;
        }
        return ans;
    }
};