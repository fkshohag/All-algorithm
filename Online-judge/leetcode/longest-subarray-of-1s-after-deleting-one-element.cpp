#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
 * Time complexity O(n)
 * Space Complexity O(1)
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, zeroCount = 0, startIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            zeroCount += (nums[i] == 0);
            while (zeroCount > 1) {
                zeroCount -= (nums[startIndex] == 0);
                startIndex++;
            }
            ans = max(ans, i - startIndex);
        }
        return ans;
    }
};