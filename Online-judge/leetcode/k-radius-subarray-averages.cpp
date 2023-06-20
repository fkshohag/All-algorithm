
# include <bits/stdc++.h>
#define ll long long
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/k-radius-subarray-averages/description/
 * Running complexity O(n)
 * Memory complexity O(n)
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = (int) nums.size();
        if (k == 0) {
            return nums;
        }

        vector<int> averages(n, -1);
        if (n < (2 * k +1)) {
            return averages;
        }

        vector<ll> prefix(n + 1, 0);
        for (int index = 0; index < n; index++) {
            prefix[index + 1] = prefix[index] + nums[index];  
        }

        for (int index = k; index < (n - k); index++) {
            int leftIndex = index - k, rightIndex = index + k;
            ll subArraySum = prefix[rightIndex + 1] - prefix[leftIndex];
            int average = subArraySum / (2 * k + 1);
            averages[index] = average;
        }
        return averages;
    }
};