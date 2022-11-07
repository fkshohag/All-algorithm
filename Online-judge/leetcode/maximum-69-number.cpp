# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-69-number/description/
 * Running complexity O(n)
 * Memory complexity O(n)
*/

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }   
        return stoi(s);
    }
};