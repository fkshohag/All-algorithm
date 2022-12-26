# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/meeting-rooms-ii/solutions/
 * Time complexity O(NlogN)
 * Space complexity O(N)
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (!intervals.size()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        int room = 1;
        
        for (int index = 1; index < intervals.size(); index++) {
            if (intervals[index][0] < pq.top()) {
                room++;
            } else {
                pq.pop(); // Not a important min heap alwasy sort by min value
            }
            pq.push(intervals[index][1]);
        }
        return room;
    }
};