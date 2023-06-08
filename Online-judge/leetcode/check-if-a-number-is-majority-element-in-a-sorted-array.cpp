# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/description/
 */


/**
 * @brief 
 * Time complexity: O(N)
 * Space complexity: O(N)
 */
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        if (freq[target] > nums.size() / 2) {
            return true;
        }
        return false;
    }
};

/**
 * @brief 
 * Time complexity: O(Log(n))
 * Space complexity: O(1)
 */
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        return upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target) > nums.size() / 2;
    }
};