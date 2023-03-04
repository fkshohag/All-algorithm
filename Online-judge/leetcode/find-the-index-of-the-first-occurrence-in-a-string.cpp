#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 * Time complexity: O(n) n is the length of S.
 * Space complexity O(1)
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int notFound = -1;
        if (needle.size() > haystack.size()) return notFound;
        if (needle.size() == 0) return 0;
        if (haystack == needle) return 0;

        for (int index = 0; index <= haystack.size() - needle.size(); index++) {
            string subStr = haystack.substr(index, needle.size());
            if (subStr == needle) return index;
        }
        return  notFound;
    }
};