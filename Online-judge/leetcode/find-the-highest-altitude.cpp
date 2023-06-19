# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-the-highest-altitude
 * Running complexity O(n)
 * Memory complexity O(n)
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> gainSum(n + 1, 0);

        for (int i = 0; i < gain.size(); i++) {
            gainSum[i + 1] = gainSum[i] + gain[i];
        }
        
        int mx = INT_MIN;
        for (int val : gainSum) {
            mx = max(mx, val);
        }
        return mx;
    }
};