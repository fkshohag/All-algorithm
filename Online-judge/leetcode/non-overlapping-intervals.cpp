# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/non-overlapping-intervals/description/
 * Time complexity O(N)
 * Space complexity O(1)
*/


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });

        int lastEnd = INT_MIN;
        int ans = 0;

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (start >= lastEnd) {
                lastEnd = end;
            } else {
                ans++;
            }
        }
        return ans;
    }
};