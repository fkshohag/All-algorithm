#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/best-team-with-no-conflicts/description/
 * Time complexity O(n^2)
 * Space Complexity O(n)
 */

typedef pair<int, int> p;
class Solution {
private:
    int n;
    int highScore(vector<p>& ageVsScore) {
        int ans = 0;
        vector<int> dp(n);
        for (int index = 0; index < n; index++) {
            dp[index] = ageVsScore[index].second;
            ans = max(dp[index], ans);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (ageVsScore[i].second >= ageVsScore[j].second) {
                    dp[i] = max(dp[i], ageVsScore[i].second + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = (int) scores.size();
        vector<p> ageVsScore;

        for (int index = 0; index < n; index++) {
            ageVsScore.push_back({ages[index], scores[index]});
        }
        sort(ageVsScore.begin(), ageVsScore.end());
        return highScore(ageVsScore);
    }
};