# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/make-the-string-great/description/
 * Running complexity O(n^2)
 * Memory complexity O(n)
*/

class Solution {
public:
    string makeGood(string s) {
        while(s.size() > 1) {
            bool find = false;
            for (int i = 0; i < s.size() - 1; i++) {
                if (abs(s[i] - s[i+1]) == 32) {
                    s = s.substr(0, i) + s.substr(i+2);
                    find = true;
                    break;
                }
            }
            if (!find) {
                break;
            }
        }
        return s;
    }
};

 // Running complexity O(n)
 // Memory complexity O(n)
class Solution {
public:
    string makeGood(string s) {
        vector<char> stack;
        for (char ch : s) {
            if (stack.size() && abs(stack.back() - ch) == 32) {
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }
        string ans(stack.begin(), stack.end());
        return ans;
    }
};