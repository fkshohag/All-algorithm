# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/make-array-strictly-increasing/
 * time complexity O(m.n.log(n))
 * space complexity O(n)
 * 
 * **/

class Solution {
private:
    vector<unordered_map<int,int>>dp;

    int solve(int index, int prev, vector<int>& arr1, vector<int>& arr2) {
        if (index == arr1.size()) return 0;
        if (this->dp[index].find(prev) != this->dp[index].end()) {
            return this->dp[index][prev];
        }

        int choice1 = 1e9, choice2 = 1e9;
        if (arr1[index] > prev) {
            choice1 = this->solve(index + 1, arr1[index], arr1, arr2);
        }

        int takeIndex = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (takeIndex != arr2.size()) {
            choice2 = this->solve(index + 1, arr2[takeIndex], arr1, arr2) + 1; 
        }
        return this->dp[index][prev] = min(choice1, choice2);
    }
    
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        this->dp.resize(2005);

        int ans = this->solve(0, -1, arr1, arr2);
        if (ans == 1e9) return -1;
        return ans;
    }
};