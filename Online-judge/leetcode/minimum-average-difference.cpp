#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-average-difference/description/
 * Time complexity: O(n).
 * Space complexity: O(1) we just took four pointer.
 */

class Solution {
public:
    typedef long long ll;
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        ll total = 0;
        ll minDiff = INT_MAX;
        int ans = -1;
        ll currentSum = 0;

        for (int index = 0; index < nums.size(); index++) {
            total += nums[index];
        }

        for (int index = 0; index < nums.size(); index++) {
            currentSum += nums[index];
            ll leftAvarage = (currentSum / (index + 1)); 
            ll rightAvarage = total - currentSum;

            if (index != (n - 1)) {
                rightAvarage /= (n - index - 1);
            }

            int currentDiff = int(abs(leftAvarage - rightAvarage));
            if (currentDiff < minDiff) {
                minDiff = currentDiff;
                ans = index;
            }
        }
        return ans;
    }
};