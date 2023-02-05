#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 * Time complexity: O(n) n is the length of S.
 * Space complexity: O(1) as constant extra space.
 */


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        if (sLen < pLen) return {};

        vector<int> ans;
        vector<int> slide(26, 0);
        vector<int> window(26, 0);

        for (int index = 0; index < pLen; index++) {
            slide[p[index] - 'a']++;
            window[s[index] - 'a']++;
        }
        if (slide == window) ans.push_back(0);
        for (int index = pLen; index < sLen; index++) {
            window[s[index - pLen] - 'a']--;
            window[s[index] - 'a']++;
            if (slide == window) {
                ans.push_back(index - pLen + 1);
            }
        }
        return ans;
    }
};