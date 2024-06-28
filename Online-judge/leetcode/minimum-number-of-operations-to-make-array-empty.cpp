# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
 * Time complexity: O(nlogn), sorting
 * Space complexity: O(1)
*/


/**
* sort by second = [[1, 6], [2, 8], [7, 12], [10, 16]]
* overlap means we don't need to count increase 
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