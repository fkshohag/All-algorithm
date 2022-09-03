# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 */

class Solution {
public:
    typedef pair<int, int>edge;
    typedef vector<vector<pair<int, int>>> graph;
    
    int djikstra(graph const& g, int const start, int const distanceThreshold) {
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        vector<int>dist(g.size(), INT_MAX);
        dist[start] = 0;
        pq.push(make_pair(start, 0));
        
        while(!pq.empty()) {
            auto [node, distance] = pq.top();
            pq.pop();
            if (distance > dist[node]) continue;
            if (distance > distanceThreshold) continue;
            
            for (auto [neigbourNode, neigbourNodeDistance] : g[node]) {
                if (distance + neigbourNodeDistance < dist[neigbourNode]) {
                    dist[neigbourNode] = distance + neigbourNodeDistance;
                    pq.push({neigbourNode, distance + neigbourNodeDistance});
                }
            }
        }
        return count_if(dist.begin(), dist.end(), [distanceThreshold](int x)->bool{return x <= distanceThreshold;});
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        graph g(n);
        
        for (const auto& edge : edges) {
            g[edge[0]].push_back(make_pair(edge[1], edge[2]));
            g[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int ans = -1;
        int min = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int mini = djikstra(g, i, distanceThreshold);
            if (mini <= min) {
                min = mini;
                ans = i;
            }
        }
        return ans;
    }
};