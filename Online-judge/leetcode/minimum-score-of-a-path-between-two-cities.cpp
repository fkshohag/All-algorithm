#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
 * Time complexity: O(n+e)
 * Space complexity: O(n+e) 
 */


typedef pair<int, int> p;

class Solution {
private:
    int minCost (int source, int n, vector<vector<p>>& graph) {

        vector<bool> visited(n, false);
        int ans = INT_MAX;
        queue<int> Q;
        Q.push(source);
        visited[source] = true;
        
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto& edge : graph[u]) {
                ans = min(ans, edge.second);
                if (!visited[edge.first]) {
                    visited[edge.first] = true;
                    Q.push(edge.first);
                }
            }
        }
        return ans;
    }
    
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<p>> graph(n + 1);

        for (auto& edge : roads) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        return minCost(1, n, graph);
    }
};