#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/binary-search/description/
 */

/**
 * @brief 
 * Time complexity : O(log(n))
 * Space complexity: O(1)
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = (int) nums.size() - 1, ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;
                break;
            }
            else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};