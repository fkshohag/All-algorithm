# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/search-insert-position/description/
 * Running complexity O(logn)
 * Memory complexity O(1)
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = (int) nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};