#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/
 * Time complexity O(n)
 * Space Complexity O(n)
 */


class Solution {
private: 
    int n;
    void bfs(int startNode, vector<int>& edges, vector<int>& dist) {
        vector<bool> visit(n, false);
        dist[startNode] = 0;
        queue<int> q;
        q.push(startNode);

        while(!q.empty()) {
            int node = q.front(); q.pop();
            if (visit[node]) continue;

            visit[node] = true;
            int neighbor = edges[node];
            if (neighbor != -1 && !visit[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);

        int minNode = -1, currentDist = INT_MAX;
        for (int currentNode = 0; currentNode < n; currentNode++) {
            if (currentDist > max(dist1[currentNode], dist2[currentNode])) {
                minNode = currentNode;
                currentDist = max(dist1[currentNode], dist2[currentNode]);
            }
        }
        return minNode;
    }
};