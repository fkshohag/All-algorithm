#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/detonate-the-maximum-bombs/
 * Time complexity: O(n^3).
 * Space complexity: O(n^2)
 **/

#define ll long long
class Solution {
private:
    int n;
    int dfs(int curr, vector<bool>& visited, vector<vector<int>>& graph) {
        visited[curr] = true;
        for (int neighbour : graph[curr]) {
            if (!visited[neighbour]) {
                dfs(neighbour, visited, graph);
            }
        }

        int count = 0;
        for (int i = 0; i < this->n; i++) {
            if (visited[i]) {
                count++;
            }
        }
        return count;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        this->n = bombs.size();
        vector<vector<int>> graph(this->n + 1);

        for (int u = 0; u < this->n; u++) {
            ll xu = bombs[u][0];
            ll yu = bombs[u][1];
            ll ru = bombs[u][2];

            for (int v = 0; v < this->n; v++) {
                ll xv = bombs[v][0];
                ll yv = bombs[v][1];

                ll dsq = (xu - xv) * (xu - xv) + (yu - yv) * (yu - yv);
                if (dsq <= ru * ru) {
                    graph[u].push_back(v);
                }
            }
        }
        
        int ans = 0;
        for (int node = 0; node < this->n; node++) {
            vector<bool> visited(this->n + 1, false);
            ans = max(ans, this->dfs(node, visited, graph));
        }
        return ans;
    }
};