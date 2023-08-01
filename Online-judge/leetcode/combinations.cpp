# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/combinations/description/
 * O(n^k)
*/

class Solution {
private:
    vector<vector<int>> ans;
    void solve(vector<int>& curr, int n, int pos, int k) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = pos; i <= n; i++) {
            curr.push_back(i);
            solve(curr, n, i + 1, k);
            curr.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(curr, n, 1, k);
        return ans;
    }
};