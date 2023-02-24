#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 */

/**
 * @brief 
 * Time complexity : O(log(n))
 * Space complexity: O(1)
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = (int) nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};