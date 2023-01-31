#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/game-of-nim/description/
 * Time complexity O(n)
 * Space Complexity O(1)
 */

class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int ans = 0;
        for (int pile : piles) {
            ans ^= pile;
        }
        return ans;
    }
};