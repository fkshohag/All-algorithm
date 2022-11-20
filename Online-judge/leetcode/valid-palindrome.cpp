#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/valid-palindrome/description/
 */



class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        
        for (int index = 0; index < s.size(); index++) {
            char ch = s[index];
            if (isalpha(ch)) {
                if (isupper(ch)) {
                    ch = tolower(s[index]);
                }
                ans.push_back(ch);
            } else if (isdigit(ch)) {
                ans.push_back(ch);
            }
        }

        int start = 0, end = ans.size() - 1;
        while (start <= end) {
            if (ans[start] != ans[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};