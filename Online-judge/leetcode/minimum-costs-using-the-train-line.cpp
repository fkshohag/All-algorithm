#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-costs-using-the-train-line/description/
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

# define ll long long
const int REGULAR_LANE = 1;
const int EXPRESS_LANE = 0;

class Solution {
private:
    vector<vector<ll>> dp;
    int n;

    ll solve(int stop, int lane, vector<int>& regular, vector<int>& express, int expressCost) {
        if (stop < 0) {
            return 0;
        }
        if (dp[stop][lane] != -1) return dp[stop][lane];

        ll regularLaneCost = regular[stop] + solve(stop - 1, REGULAR_LANE, regular, express, expressCost);
        ll expressLaneCost = (lane ? expressCost : 0) + express[stop] + solve(stop - 1, EXPRESS_LANE, regular, express, expressCost);

        dp[stop][lane] = min(regularLaneCost, expressLaneCost);
        return dp[stop][lane];
    }

public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        n = regular.size();
        dp = vector<vector<ll>>(n, vector<ll>(2, -1));

        solve(n - 1, REGULAR_LANE, regular, express, expressCost);
        vector<ll> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(dp[i][1]);
        }
        return ans;
    }
};