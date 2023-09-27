#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/decoded-string-at-index
 * T.C: O(n)
 * S.C: O(n)
 */

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long size = 0;
        int N = s.size();
        
        for (int i = 0; i < N; i++) {
            if (isdigit(s[i])) {
                size *= s[i] - '0';
            } else {
                size++;
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            k %= size;
            if (k == 0 && isalpha(s[i])) {
                return (string) "" + s[i];
            }
            if (isdigit(s[i])) {
                size /= s[i] - '0';
            } else {
                size --;
            }
        }
        return "";
    }
};