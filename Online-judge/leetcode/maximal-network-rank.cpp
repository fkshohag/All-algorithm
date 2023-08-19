#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximal-network-rank/description/
 * Complexity: running O(E + V^2)
 * Space complexity: O(E)
 */

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> graph;

        for (vector<int> road : roads) {
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }

        int maxRank = 0;
        for (int node1 = 0; node1 < n; node1++) {
            for (int node2 = node1 + 1; node2 < n; node2++) {
                int currentRank = graph[node1].size() + graph[node2].size();
                if (graph[node1].count(node2)) {
                    currentRank --;
                }
                maxRank = max(maxRank, currentRank);
            }
        }
        return maxRank;
    }
};