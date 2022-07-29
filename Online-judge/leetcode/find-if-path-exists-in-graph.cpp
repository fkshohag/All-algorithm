# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-if-path-exists-in-graph/
 */

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> g[n+1];
        
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visit (n+1, false);
        queue<int> q;
        visit[source] = true;
        q.push(source);
        
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (int i = 0; i < g[u].size(); i++) {
                int v = g[u][i];
                if (!visit[v]) {
                    q.push(v);
                    visit[v] = true;
                }
            }
        }
        return visit[destination];
    }
};