#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/median-of-two-sorted-arrays/
 * T.C: O(m + n)
 * S.C: O(m + n)
 */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
		for (int num : nums1) {
			nums.push_back(num);
		}
		for (int num : nums2) {
			nums.push_back(num);
		}

		sort(nums.begin(), nums.end());
		int size = nums.size();
		int index = size / 2;

		if (size % 2 == 0) {
			return  ((double)(nums[index] + nums[index - 1]) / 2);
		}
		return (double) nums[index];
    }
};