# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/insert-interval/description/
 * Time complexity O(NlogN)
 * Space complexity O(N) / LogN
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0];
        });

        vector<vector<int>>ans;
        for (auto& interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = max(interval[1], ans.back()[1]);
            }
        }
        return ans;
    }
};