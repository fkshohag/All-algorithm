#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/shortest-path-with-alternating-colors/
 * Time complexity: O(n+e) n is the length of fruits.
 * Space complexity: O(n+e) 
 */



typedef pair<int, int> p;
const int RED = 0, BLUE = 1, UNKNOWN = -1;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<p>> graph(n);

        for (auto& edge : redEdges) {
            graph[edge[0]].push_back({edge[1], RED});
        }
        for (auto& edge : blueEdges) {
            graph[edge[0]].push_back({edge[1], BLUE});
        }

        queue<vector<int>> Q;
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        vector<int> distance(n, -1);

        distance[0] = 0;
        Q.push({0, 0, UNKNOWN});
        visited[0][1] = visited[0][0] = true;

        while(!Q.empty()) {
            auto element = Q.front(); Q.pop();
            int node = element[0], steps = element[1], prevColor = element[2];

            for (auto& [neighbor, color] : graph[node]) {
                if (!visited[neighbor][color] && color != prevColor) {
                    visited[neighbor][color] = true;
                    Q.push({neighbor, steps + 1, color});
                    if (distance[neighbor] == -1) distance[neighbor] = steps + 1;
                }
            } 
        }
        return distance;
    }
};