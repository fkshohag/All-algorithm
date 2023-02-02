#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
 * Time complexity O(m+n)
 * Space Complexity O(m+n)
 */

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1+str2 != str2+str1) return "";
        return (str1.substr(0, gcd(str1.size(), str2.size())));
    }
};