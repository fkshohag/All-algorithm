#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/group-anagrams/description/
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        for (int index = 0; index < strs.size(); index++) {
            string key = strs[index];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[index]);
        }
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};