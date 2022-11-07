# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/orderly-queue/discussion/
 * Running complexity for k = 1 O(n) and for k > 1 O(n^2)
 * Memory complexity O(1)
*/


class Solution {
public:
    string orderlyQueue(string s, int k) {
        string temp = s;
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        } else {
            s += s;
            for (int i = 1; i < temp.size(); i++) {
                temp = min(temp, s.substr(i, temp.size()));
            }
        }
        return temp;
    }
};