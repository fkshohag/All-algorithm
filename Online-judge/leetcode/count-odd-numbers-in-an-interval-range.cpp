#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/
 * Time complexity: O(1) 
 * Space complexity: O(1) 
 */

class Solution {
public:
    int countOdds(int low, int high) {
        if (!(low & 1)) {
            low++;
        }
        return low > high ? 0 : (high - low) / 2 + 1;
    }
};