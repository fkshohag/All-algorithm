#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/wiggle-sort/description/
 * Time complexity: O(n) n is the length of fruits.
 * Space complexity: O(1) 
 */

class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if ((i % 2 == 0 && nums[i] > nums[i + 1]) || 
                (i % 2 == 1 && nums[i] < nums[i + 1])
            ) {
                swap(nums, i , i + 1);
            }
        }
    }
};