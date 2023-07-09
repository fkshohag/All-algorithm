#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/substring-with-largest-variance/description/
 * Time complexity O(n * k ^ 2)
 * Space Complexity O(1)
 */

class Solution {
public:
    int largestVariance(string s) {
        unordered_set<char> unique(s.begin(), s.end());
        int maxVariance = 0, count1 = 0, count2 = 2;

        for (int i = 0; i < 2; i++) {
            for (char ch1 : unique) {
                for (char ch2 : unique) {
                    if (ch1 == ch2) {
                        continue;
                    }
                    
                    count1 = 0, count2 = 0;
                    for (char letter : s) {
                        if (letter == ch1) {
                            count1++;
                        } else if (letter == ch2) {
                            count2++;
                        }
                        if (count1 < count2) {
                            count1 = count2 = 0;
                        } else if (count1 > 0 && count2 > 0) {
                            maxVariance = max(maxVariance, count1 - count2);
                        }
                    }
                }
            }
            reverse(s.begin(), s.end());
        }
        return maxVariance;
    }
};