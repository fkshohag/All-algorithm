#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/permutation-in-string/description/
 * Time complexity: O(n) n is the length of S.
 * Space complexity: O(1) as constant extra space.
 */


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int slen = s1.length(), sslen = s2.length();
        if (sslen < slen) return false;
        vector<int> slide(26, 0), window(26, 0);

        for (int index = 0; index < slen; index++) {
            slide[s1[index] - 'a']++;
            window[s2[index] - 'a']++;
        }

        if (slide == window) return true;
        for (int index = slen; index < sslen; index++) {
            window[s2[index - slen] - 'a']--;
            window[s2[index] - 'a']++;
            if (slide == window) return true;
        }
        return false;
     }
};