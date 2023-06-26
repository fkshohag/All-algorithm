# include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
 * @brief 
 * Problem: https://leetcode.com/problems/total-cost-to-hire-k-workers/description/
 * Time complexity: O((k+m).logm)
 * Space complexity: O(m)
 */

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        int i = 0, j = costs.size() - 1;
        ll ans = 0;

        while (k--) {
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i++]);
            }
            while (pq2.size() < candidates && i <= j) {
                pq2.push(costs[j--]);
            }

            int c1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int c2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (c1 <= c2) {
                ans += c1;
                pq1.pop();
            } else {
                ans += c2;
                pq2.pop();
            }
        }
        return ans;
    }
};