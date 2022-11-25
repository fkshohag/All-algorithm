# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/combination-sum/
 * O(n^2)
*/

class Solution {
private:
    void sum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& r, int index) {
        if (target == 0) {
            res.push_back(r);
        }
        while (index < candidates.size() && target >= 0) {
            r.push_back(candidates[index]);
            sum(candidates, target - candidates[index], res, r, index);
            index++;
            r.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> r;
        sum(candidates, target, res, r, 0);
        return res;
    }
};