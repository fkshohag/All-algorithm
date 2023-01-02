# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/detect-capital/description/
 * Time complexity O(n)
 * Memory complexity O(1)
*/


class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        if (word.size() == 1) return true;
        for (int index = 0; index < word.size(); index++) {
            if (isupper(word[index])) {
                count++;
            }
        }
        if (count == 0 || count == word.size()) return true;
        if (count == 1 && isupper(word[0])) return true;
        return false;
    }
};