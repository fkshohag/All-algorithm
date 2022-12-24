#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-cost-to-connect-sticks/description/
 * Time Complexity: O(NlogN) Adding N elements to the priority queue will be O(NlogN)
 * Space Complexity: O(N) since we will store N elements in our priority queue
 */


class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int ans = 0;
        if (sticks.size() == 1) return 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int number : sticks) pq.push(number);
        int x = 0, y = 0, sum = 0;

        while(pq.size() > 1) {
            x = pq.top(); pq.pop();
            y = pq.top(); pq.pop(); 
            sum = x + y; ans += sum;
            pq.push(sum);
        }
        return ans;
    }
};