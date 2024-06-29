# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
 * Time complexity: O(n)
 * Space complexity: O(n)
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int ans = 0;
        for (auto [_, count]: freq) {
            if (count == 1) {
                return -1;
            }
            ans += ceil((double)count / 3);
        }
        return ans;
    }
};