# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/nim-game/
 */


class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4 != 0) return true;
        return false;
    }
};