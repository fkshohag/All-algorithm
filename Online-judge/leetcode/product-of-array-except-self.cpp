#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/product-of-array-except-self/description/
 * Time complexity: O(n).
 * Space complexity: O(n).
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums), postfix(nums), ans(size(nums));
        int rIndex = nums.size() - 2;

        for (int index = 1; index < prefix.size(); index++) {
            prefix[index] *= prefix[index -1];
            postfix[rIndex] *= postfix[rIndex + 1];
            rIndex--;
        }
        
        for (int index = 0; index < nums.size(); index++) {
            ans[index] = (index ? prefix[index - 1] : 1) * (index + 1 < size(nums) ? postfix[index + 1] : 1);
        }
        return ans;
    }
};