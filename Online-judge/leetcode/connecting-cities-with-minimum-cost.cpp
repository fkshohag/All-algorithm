#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/connecting-cities-with-minimum-cost/description/
 * Time Complexity: O(eloge * log*n) = O(elog*n)
 * Space complexity: O(E)
 */

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:

    UnionFind(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool makeUnion(int x, int y) {
        int xx = find(x);
        int yy = find(y);

        if (xx == yy) return false;
        if (size[xx] < size[yy]) {
            swap(xx, yy);
        }

        parent[yy] = xx;
        size[xx] += yy;

        return true;
    } 
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        UnionFind u(n);
        int ans = 0;
        int totalEdges = 0;
        
        sort(connections.begin(), connections.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        for (auto& connection : connections) {
            if (u.makeUnion(connection[0], connection[1])) {
                ans += connection[2];
                totalEdges += 1;
            }
        }
        if (totalEdges == n - 1) {
            return ans;
        }
        return -1;
    }
};