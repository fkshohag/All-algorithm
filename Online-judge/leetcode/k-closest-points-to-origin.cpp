#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/k-closest-points-to-origin/
 * Complexity: running O(nlogk)
 * Space complexity: O(k)
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        
        for (vector<int> point: points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            pq.push({dist, {point[0], point[1]}});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            ans.push_back({top.second.first, top.second.second});
        }
        return ans;
    }
};