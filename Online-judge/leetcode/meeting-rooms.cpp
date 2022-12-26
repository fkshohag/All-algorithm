# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/meeting-rooms/description/
 * Time complexity O(NlogN)
 * Space complexity O(N)
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (!intervals.size() || intervals.size() == 1) return true;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0];
        });

        priority_queue<int> pq;
        pq.push(intervals[0][1]);

        for (int index = 1; index < intervals.size(); index++) {
            if (intervals[index][0] < pq.top()) {
                return false;
            } else {
                pq.pop();
            }
            pq.push(intervals[index][1]);
        }
        return true;
    }
};