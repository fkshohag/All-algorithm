#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
 * Time Complexity: O(eloge + e^2.a(n)) => O(e^2.a(n))
 * Space complexity: O(E)
 */


class Disjoint {
public:
    vector<int> parent;
    vector<int> size;
    int maxSize;
    
    Disjoint(int n) {
        parent.resize(n);
        size.resize(n, 1);
        maxSize = 1;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    bool makeUnion(int x, int y) {
        int xx = findParent(x);
        int yy = findParent(y);
        if (xx == yy) return false;

        if (size[xx] < size[yy]) {
            swap(xx, yy);
        }
        parent[yy] = xx;
        size[xx] += size[yy];
        maxSize = max(maxSize, size[xx]);
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> newEdges = edges;
        int eSize = newEdges.size();

        for (int i = 0; i < eSize; i++) {
            newEdges[i].push_back(i);
        }
        sort(newEdges.begin(), newEdges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        Disjoint actualMst(n);
        int actualMstWeight = 0;
        for (const auto& edge : newEdges) {
            if (actualMst.makeUnion(edge[0], edge[1])) {
                actualMstWeight += edge[2]; 
            }
        }

        vector<vector<int>> ans(2);
        for (int i = 0; i < eSize; i++) {
            Disjoint ignoreMst(n);
            int ignoreMstWeight = 0;
            for (int j = 0; j < eSize; j++) {
                if (i != j && ignoreMst.makeUnion(newEdges[j][0], newEdges[j][1])) {
                    ignoreMstWeight += newEdges[j][2];
                }
            }
            if (ignoreMst.maxSize < actualMst.maxSize || ignoreMstWeight > actualMstWeight) {
                ans[0].push_back(newEdges[i][3]);
            } else {
                Disjoint forceMst(n);
                forceMst.makeUnion(newEdges[i][0], newEdges[i][1]);
                int forceMstWeight = newEdges[i][2];

                for (int j = 0; j < eSize; j++) {
                    if (i != j && forceMst.makeUnion(newEdges[j][0], newEdges[j][1])) {
                        forceMstWeight += newEdges[j][2];
                    }
                }
                if (forceMstWeight == actualMstWeight) {
                    ans[1].push_back(newEdges[i][3]);
                }
            }
        }
        return ans;
    }
};