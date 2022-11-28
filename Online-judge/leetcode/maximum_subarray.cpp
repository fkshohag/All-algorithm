# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-subarray/
 * O(n)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largestSum = INT_MIN;
        int largest = 0;
        for (int index = 0 ; index < nums.size(); index++) {
            largest = max(nums[index], largest + nums[index]);
            largestSum = max(largest, largestSum);
        }
        return largestSum;
    }
};

/*
O(n^2)
for (int index = 0 ; index < nums.size(); index++) {
    int largest = 0;
    for (int jIndex = index; jIndex < nums.size(); jIndex++) {
        largest += nums[jIndex];
        largestSum = max(largest, largestSum);
    }
}

*/