# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long subarray = 0, ans = 0;
        for (int num : nums) {
            if (num == 0) {
                subarray++;
            } else {
                subarray = 0;
            }
            ans += subarray;
        }
        return ans;
    }
};