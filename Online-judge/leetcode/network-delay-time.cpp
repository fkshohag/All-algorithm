#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/network-delay-time/description
 * Time complexity O(N + E log N)
 * Space Complexity O(N + E)
 */

typedef pair<int, int> p;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>> graph(n+1);
        for (vector<int> time : times) {
            graph[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, k});
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        
        while (!pq.empty()) {
            auto [utime, unode] = pq.top();
            pq.pop();

            for (auto [vnode, vtime] : graph[unode]) {
                if (distance[unode] + vtime < distance[vnode]) {
                    distance[vnode] = distance[unode] + vtime;
                    pq.push({distance[vnode], vnode});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, distance[i]);
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};