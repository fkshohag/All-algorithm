#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/optimal-account-balancing/description/
 * Time complexity O((n-1)!)
 * Space Complexity O(n)
 */

#define pb push_back
#define ll long long

class Solution {
private:
    vector<ll> debt;
    int dfs(int personId) {
        if (personId == this->debt.size()) {
            return 0;
        }
        if (this->debt[personId] == 0) {
            return this->dfs(personId + 1);
        }

        int minTransactions = INT_MAX;
        for (int nextPersonId = personId + 1; nextPersonId < this->debt.size(); nextPersonId++) {
            if (this->debt[personId] * this->debt[nextPersonId] < 0) {
                this->debt[nextPersonId] += this->debt[personId];
                minTransactions = min(minTransactions, this->dfs(personId + 1) + 1);
                this->debt[nextPersonId] -= this->debt[personId];
            }
        }
        return minTransactions;
    }
    
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balances;
        for (vector<int> t : transactions) {
            balances[t[0]] -= t[2];
            balances[t[1]] += t[2];
        }
        for (auto b : balances) {
            if (b.second != 0) {
                this->debt.pb(b.second);
            }
        }

        return this->dfs(0);
    }
};