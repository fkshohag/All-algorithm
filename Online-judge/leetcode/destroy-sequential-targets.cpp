# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/destroy-sequential-targets/description/
 * time complexity O(n)
 * space complexity O(n)
*/

class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> freq;
        int target = 0;

        for (int num : nums) {
            target = max(target, ++freq[num % space]);
        }

        int ans = INT_MAX;
        for (int num : nums) {
            if (freq[num % space] == target) {
                ans = min(ans, num);
            }
        }
        return ans;
    }
};