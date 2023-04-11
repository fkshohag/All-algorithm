# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 * Time complexity: O((N + E) * K)
 * Space complexity: O(N)
 */



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;

        for (int step = 0; step <= k; step++) {
            vector<int> temp(dist);
            for (auto& flight : flights) {
                if (dist[flight[0]] != INT_MAX) {
                    temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};