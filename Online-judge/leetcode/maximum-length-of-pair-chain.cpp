# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 * Time complexity  O(nlogn)
 * Space complexity O(1)
*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>&a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int len = 1, prevIndex = 0;
        for (int index = 1; index < pairs.size(); index++) {
            if (pairs[index][0] > pairs[prevIndex][1]) {
                prevIndex = index;
                len++;
            }
        } 
        return len;
    }
};