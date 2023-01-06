# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 * Time complexity: O(nlogn), sorting
 * Space complexity: O(1)
*/


/**
* sort by second = [[1, 6], [2, 8], [7, 12], [10, 16]]
* overlap means we don't need to count increase 
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 1;
        int ending = points[0][1];
        for (auto point : points) {
            if (point[0] > ending) {
                ans++;
                ending = point[1];
            }
        }
        return ans;
    }
};