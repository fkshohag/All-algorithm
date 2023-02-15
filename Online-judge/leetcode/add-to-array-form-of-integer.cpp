# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/add-to-array-form-of-integer/description/
 * Time complexity: O(max(N, logk)) where N is the length of nums
 * Space complexity: O(max(N, logk))
 */

/*
Explanation:
  1 2 3 nums array
+ 9 1 2 k
--------------
1 0 3 5

123 + 912 
we start [1, 2, 3+ 912]
second [1, 2+91, 5]
third [1+9, 3, 5]
four [10, 3, 5]
ans = [1, 0, 3, 5]

*/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int N = nums.size();
        int cur = k;
        vector<int> ans;

        int i = N;
        while(--i >= 0 || cur > 0) {
            if (i >= 0) cur += nums[i];
            ans.push_back(cur % 10);
            cur /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};