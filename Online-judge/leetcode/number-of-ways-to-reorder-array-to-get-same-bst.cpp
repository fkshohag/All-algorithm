# include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/
 * Time complexity O(m^2)
 * Space complexity O(m^2)
*/

class Solution {
private:
    vector<vector<ll>> table;
    ll mod = 1e9 + 7;

    ll dfs(vector<int>& nums) {
        int m = (int) nums.size();
        if (m <= 2) return 1;
        vector<int> leftTree, rightTree;

        for (int i = 1; i < m; i++) {
            if (nums[i] < nums[0]) {
                leftTree.pb(nums[i]);
            }
            else {
                rightTree.pb(nums[i]);
            }
        }
        
        ll leftWays = dfs(leftTree) % mod;
        ll rightWays = dfs(rightTree) % mod;
        return (((leftWays * rightWays) % mod) * table[m - 1][leftTree.size()]) % mod;
    }
    
public:
    int numOfWays(vector<int>& nums) {
        ll m = nums.size();
        table.resize(m + 1);

        for (int i = 0; i < m + 1; i++) {
            table[i] = vector<ll>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        return (dfs(nums) - 1) % mod;
    }
};