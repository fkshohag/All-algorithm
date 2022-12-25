# include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * Time complexity O(n)
 * Space complexity O(n)
 */

class Solution {
private:
    vector<int>dp;

    int solve(int index, string& s) {
        if (s[index] == '0') return 0;
        if (index == s.size()) return 1;
        if (index == s.size() - 1) return 1;
        if (dp[index] != -1) return dp[index];

        int ans = solve(index+1, s);
        if (stoi(s.substr(index, 2)) <= 26) {
            ans += solve(index + 2, s);
        }
        return dp[index] = ans;
    }
public:
    int numDecodings(string s) {
        dp = vector<int>(s.size() + 1, -1);
        return solve(0, s);
    }
};