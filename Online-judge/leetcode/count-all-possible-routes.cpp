
# include <bits/stdc++.h>
#define ll long long

using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/count-all-possible-routes/
 * time complexity O(n^2*fuel)
 * space complexity O(n*fuel)
*/



class Solution {
private:
    ll mod = 1e9+7;
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& locations, int currentCity, int finish, int remainingFuel) {
        if (remainingFuel < 0) return 0;
        if (this->dp[currentCity][remainingFuel] != -1) return this->dp[currentCity][remainingFuel];

        int ans = currentCity == finish ? 1 : 0;

        for (int nextCity = 0; nextCity < this->n; nextCity++) {
            if (nextCity == currentCity) continue;
            
            int diff = abs(locations[currentCity] - locations[nextCity]);
            ans = (ans + solve(locations, nextCity, finish, remainingFuel - diff)) % mod;
        }
        return this->dp[currentCity][remainingFuel] = ans;
    }
    
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        dp = vector<vector<int>>(this->n, vector<int>(fuel + 1, -1));

        return this->solve(locations, start, finish, fuel);
    }
};