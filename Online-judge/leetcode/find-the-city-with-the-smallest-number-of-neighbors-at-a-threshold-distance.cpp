# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 */


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> citys(n, vector<int>(n, INT_MAX / 2));
        
        // self cost = 0
        for (int i = 0; i < n; i++) {
            citys[i][i] = 0;
        }
        
        for (const auto& e : edges) {
            int source = e[0];
            int destination = e[1];
            int cost = e[2];
            citys[source][destination] = cost;
            citys[destination][source] = cost;
        }
        
        // Every city distance calculating 
        for (int city = 0; city < n; city++) {
            for (int sCity = 0; sCity < n; sCity++) {
                for (int dCity = 0; dCity < n; dCity++) {
                    if (citys[sCity][city] + citys[city][dCity] < citys[sCity][dCity]) {
                        citys[sCity][dCity] = citys[sCity][city] + citys[city][dCity];
                    }
                }
            }
        }
        
        vector <int> reachables(n, 0);
        int min = INT_MAX;
        for (int sCity = 0; sCity < n; sCity++) {
            int count = 0;
            for (int dCity = 0; dCity < n; dCity ++) {
                if (citys[sCity][dCity] <=  distanceThreshold) {
                    count++;
                }
            }
            min = std::min(min, count);
            reachables[sCity] = count;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (min == reachables[i]) {
                return i;
            }
        }
        return -1;
    }
};