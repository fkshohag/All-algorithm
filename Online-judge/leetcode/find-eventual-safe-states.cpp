#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-eventual-safe-states/description/
 * Time complexity: O(M + N).
 * Space complexity: O(M + N).
 */


class Solution {
private:
    bool hasCycle(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& visiting) {
        visiting[node] = true;
        visited[node] = true;

        for (int child : graph[node]) {
            if (!visited[child]) {
                if (hasCycle(child, graph, visited, visiting)) return true;
            } else {
                if (visiting[child]) return true;
            }
        }
        visiting[node] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<bool> visited(n, false), visiting(n, false);
        
        for (int node  = 0; node < n; node++) {
            if (!hasCycle(node, graph, visited, visiting)) {
                ans.push_back(node);
            }
        }
        return ans;
    }
};