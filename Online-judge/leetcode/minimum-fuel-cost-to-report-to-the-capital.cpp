#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/
 * Time complexity: O(n) 
 * Space complexity: O(n) 
 */

class Solution {
private:
    long long fuels;
    long long dfs(int node, int parent, vector<vector<int>>& citys, int& seats) {
        int representatives = 1;
        for (int city : citys[node]) {
            if (city != parent) {
                representatives += dfs(city, node, citys, seats);
            }
        }
        if (node != 0) {
            fuels += ceil((double) representatives / seats);
        }
        return representatives;
    }

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> graph(n);

        for (auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        dfs(0, -1, graph, seats);
        return fuels;
    }
};