# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/custom-sort-string/
 * Time complexity: O(n)
 * Space complexity: O(n)
*/


class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        string ans = "";
        for (char ch : order) {
            while (mp[ch] > 0) {
                ans.push_back(ch);
                mp[ch]--;
            }
        }

        for (auto &[ch, count] : mp) {
            while (count > 0) {
                ans.push_back(ch);
                count--;
            }
        }
        return ans;
    }
};