# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/3sum/description/
 * Time complexity  O(n)
 * Space complexity O(1)
*/


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countOne = 0, flip = 0;
        for (char ch : s) {
            if (ch == '1') countOne++;
            else flip++;
            flip = min(flip, countOne);
        }
        return flip;
    }
};