# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slow = 0, rent = 0;
        map<char, int> seen;
        
        for (int fast = 0; fast < s.length(); fast++) {
            if(seen.find(s[fast]) != seen.end()) {
                slow = max(slow, seen[s[fast]] + 1);
            }
            seen[s[fast]] = fast;
            rent = max(rent, fast - slow + 1);
        }
        return rent;
    }
};