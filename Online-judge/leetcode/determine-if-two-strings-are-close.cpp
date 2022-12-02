#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/determine-if-two-strings-are-close/description/
 * Time complexity: O(n).
 * Space complexity: O(1) as constant extra space.
 */


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        if (set(word1.begin(), word1.end()) != set(word2.begin(), word2.end())) return false;
        vector<int>freq1(26, 0);
        vector<int>freq2(26, 0);

        for (int i = 0; i < word1.size(); i++) {
            int key1 = word1[i] - 'a';
            int key2 = word2[i] - 'a';
            freq1[key1]++;
            freq2[key2]++;
        }
        
        sort(freq1.rbegin(), freq1.rend());
        sort(freq2.rbegin(), freq2.rend());

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
    }
};