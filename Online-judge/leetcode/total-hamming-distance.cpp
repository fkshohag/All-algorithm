# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/total-hamming-distance/
 */

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < 32; i++) {
            int one = 0, zero = 0;
            for (int num : nums) {
                if (num & (1 << i)) {
                    one++;
                }
                else {
                    zero++;
                }
            }
            if (one == n || zero == n) continue;
            ans += (one * zero);
        }
        return ans;
    }
};