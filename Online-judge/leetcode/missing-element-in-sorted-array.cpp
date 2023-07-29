#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/missing-element-in-sorted-array/
 */

/**
 * @brief 
 * Time complexity : O(logn)
 * Space complexity: O(1)
 * Solution: 
 *  number of element = nums[i] - nums[0] + 1
 *  missing element = (nums[i] - nums[0] + 1) - (i - 1) // (i element existing in array)
 *  = nums[i] - nums[0] - 1 = nums[mid] - nums[0] - mid
 */


class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = right - (right - left) / 2;
            if (nums[mid] - nums[0] - mid < k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return nums[0] + k + left;
    }
};