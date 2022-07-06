/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/contains-duplicate/
 */

# include <iostream>
# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int index = 1; index < nums.size(); index++) {
            if (nums[index-1] == nums[index]) {
                return true;
            }
        }
        return false;
    }
};