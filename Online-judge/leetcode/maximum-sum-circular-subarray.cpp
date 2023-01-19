# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-sum-circular-subarray/description/
 * Time complexity  O(n)
 * Space complexity O(1)
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], minSum = nums[0], currentMax = 0, currentMin = 0, totalSum = 0;
        for (int num : nums) {
            currentMax = max(num, currentMax + num);
            maxSum = max(currentMax, maxSum);
            currentMin = min(num, currentMin + num);
            minSum = min(currentMin, minSum);
            totalSum += num;
        }
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};