# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
 * Running complexity O(n)
 * Memory complexity O(n)
*/

class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> stack;
        for (int index = 0; index < s.size(); index++) {
            if (stack.size() && stack.back() == s[index]) {
                stack.pop_back();
            } else {
                stack.push_back(s[index]);
            }
        }
        return string(stack.begin(), stack.end());
    }
};