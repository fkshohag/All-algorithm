# include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * Time complexity O(n)
 * Space complexity O(n)
 */
class Solution {
public:
    string removeStars(string s) {
        vector<char> v;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*' && !v.empty()) {
                v.pop_back();
            } else {
                v.push_back(s[i]);
            }
        }
        return string(v.begin(), v.end());
    }
};