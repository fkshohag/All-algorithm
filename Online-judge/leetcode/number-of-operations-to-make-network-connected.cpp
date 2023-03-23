# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
 * Time complexity: O(n+e)
 * Space complexity: O(n+e)
*/


class Solution {
private:
    void dfs(int node, vector<vector<int>>& networks, vector<bool>& visited) {
        visited[node] = true;
        for (int connectedNode : networks[node]) {
            if (!visited[connectedNode]) {
                dfs(connectedNode, networks, visited);
            }
        }
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        vector<vector<int>> networks(n);

        for (auto& connection : connections) {
            networks[connection[0]].push_back(connection[1]);
            networks[connection[1]].push_back(connection[0]);
        }
        
        vector<bool> visited(n + 1, false);
        int disconnectedNode = 0;

        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                dfs(node, networks, visited);
                disconnectedNode++;
            }
        }
        return disconnectedNode - 1;
    }
};