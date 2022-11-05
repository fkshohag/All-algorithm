# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/reverse-string/description/
 * Running complexity O(n)
 * Memory complexity O(1)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int startIndex = 0, endIndex = s.size() - 1;
        while(startIndex < endIndex) {
            swap(s[startIndex++], s[endIndex--]);
        }
    }
};