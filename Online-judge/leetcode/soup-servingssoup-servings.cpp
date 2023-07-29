#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/soup-servings/description/
 * Runing complexity O(1) We assume ϵ\epsilonϵ to be constant.
 * Space complexity O(1)
 */

class Solution {
private:
    unordered_map<int, unordered_map<int, double>> dp;
    int m;

    double calculate(int& i, int& j) {
        return 0.25 * (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][j - 1]
               + dp[max(0, i - 2)][max(0, j - 2)] + dp[i - 1][max(0, j - 3)]);
    }
    
public:
    double soupServings(int n) {
        m = ceil(n / 25.0);

        dp[0][0] = 0.5;
        for (int k = 1; k <= m; k++) {
            dp[0][k] = 1.0;
            dp[k][0] = 0.0;
            
            for (int j = 1; j <=k; j++) {
                dp[j][k] = calculate(j, k);
                dp[k][j] = calculate(k, j);
            }
            if (dp[k][k] >= 1.0) return 1.0;
        }
        return dp[m][m];
    }
};