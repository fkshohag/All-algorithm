# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/keys-and-rooms/description/
 * Time Complexity: O(N+E), where N is the number of rooms, and E is the total number of keys.
 * Space Complexity: O(N) in additional space complexity, to store stack and seen.
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> seen (rooms.size(), false);
        seen[0] = true;
        queue<int> Q;
        Q.push(0);

        while(!Q.empty()) {
            int nextRoomKey = Q.front(); Q.pop();
            for (int key : rooms[nextRoomKey]) {
                if (!seen[key]) {
                    seen[key] = true;
                    Q.push(key);
                }
            }
        }
        return count(seen.begin(), seen.end(), true) == rooms.size();
    }
};