/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/number-of-music-playlists/description/
 * Time complexity: O(n * goal)
 * Memory complexity: O(n * goal)
 */



class Solution {
protected:
    #define ll long long
    const int MOD = 1e9 + 7;
    
private:
    vector<vector<int>> dp;
    ll solve(int n, int goal, int k) {
        if (n == 0 && goal == 0) return 1;
        if (n == 0 || goal == 0) return 0;
        if (dp[n][goal] != -1) return dp[n][goal];

        ll takeNewSong = solve(n- 1, goal - 1, k) * n; // new song choice from n list
        ll repeatSong = solve(n, goal - 1, k) * max(n - k, 0); // repeat old song but skip k song
        return dp[n][goal] = (takeNewSong + repeatSong) % MOD;
    }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        dp = vector<vector<int>>(n + 1, vector<int>(goal + 1, -1));
        return solve(n, goal, k);
    }
};