#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/possible-bipartition/description/
 * Time complexity: O(N+E).
 * Space complexity: O(N+E).
 */

class Solution {
private:
    static const int READ = 0;
    static const int BLUE = 1; 
    
    bool isBipartite(int source, vector<vector<int>>& g, vector<int>& color) {
        queue<int> Q;
        Q.push(source);
        color[source] = Solution::READ;

        while(!Q.empty()) {
            int node = Q.front(); Q.pop();
            for (auto& neighbor : g[node]) {
                if (color[neighbor] == color[node]) return false;
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node]; // neighbor color = red -> blue and blue -> red 
                    Q.push(neighbor);
                }
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        vector<int> color(n + 1, -1);

        for (auto& edge : dislikes) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int node = 1; node <= n; node++) {
            if (color[node] == -1) {
                if (!isBipartite(node, graph, color)) return false;
            }
        }
        return true;
    }
};