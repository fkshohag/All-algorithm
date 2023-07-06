#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-size-subarray-sum/description/
 * Time complexity O(n)
 * Space Complexity O(1)
 */


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, ans = INT_MAX;

        for (int index = 0; index < nums.size(); index++) {
            sum += nums[index];
            
            while (sum >= target) {
                ans = min(ans, index - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};