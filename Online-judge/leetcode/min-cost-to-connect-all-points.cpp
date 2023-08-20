#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/min-cost-to-connect-all-points/description/
 * Time Complexity: O(N^2 * logN)
 * Space complexity: O(E)
 */

class UnionFind {
private:
    vector<int> parents;
    vector<int> weights;

public:
    UnionFind(int n) {
        parents.resize(n);
        weights.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (x == parents[x]) return x;
        return parents[x] = find(parents[x]);
    }

    bool makeUnion(int x, int y) {
        int xx = find(x);
        int yy = find(y);

        if (xx == yy) return false;
        if (weights[xx] < weights[yy]) {
            swap(xx, yy);
        }

        parents[yy] = xx;
        weights[xx] += yy;
        return true;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> connections;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                connections.push_back({i, j, distance});
            }
        }
        sort(connections.begin(), connections.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        UnionFind uf(n);
        int minCost = 0;
        for (auto& connection : connections) {
            if (uf.makeUnion(connection[0], connection[1])) {
                minCost += connection[2];
            }
        }
        return minCost;
    }
};