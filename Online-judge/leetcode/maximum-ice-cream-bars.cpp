# include <bits/stdc++.h>
using namespace std;

/* 
sort: 1, 1, 2, 3, 4
1 + 1 + 2 + 3 = 7 
total ice-cream = 4
*/

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-ice-cream-bars/description/
 * Time complexity O(N) if we consider sorting then O(nlogn)
 * Space complexity O(1)
*/
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        
        for (int index = 0; index < costs.size(); index++) {
            if (coins >= costs[index]) {
                coins -= costs[index];
            } else {
                return index;
            }
        }
        return costs.size();
    }
};