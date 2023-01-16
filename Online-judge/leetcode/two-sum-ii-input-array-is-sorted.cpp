# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/
 * Time complexity  O(n) 
 * Space complexity O(1)
*/

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, sum = 0;
        while (low < high) {
            sum = nums[low] + nums[high];
            if (sum == target) return {low + 1, high + 1};
            if (sum < target) {
                low++;
            } else {
                high--;
            }
        }
        return {-1, -1};
    }
};