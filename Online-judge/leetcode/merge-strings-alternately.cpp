#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/merge-strings-alternately/editorial/
 */

/**
 * @brief 
 * Time complexity : O(n + m)
 * Space complexity: O(1) we do not use more than constant space.
 */


// Two pointer
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = (int) word1.size(), m = (int) word2.size();
        int i = 0, j = 0;
        string str;

        while (i < n && j < m) {
            str.push_back(word1[i]);
            str.push_back(word2[j]);
            i++;
            j++;
        }
        if (m > n) {
            while (j < m) {
                str.push_back(word2[j]);
                j++;
            }
        } else {
            while (i < n) {
                str.push_back(word1[i]);
                i++;
            }
        }
        return str;
    }
};

// One Pointer
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string str;

        for (int index = 0; index < max(n, m); index++) {
            if (index < n) {
                str.push_back(word1[index]);
            }
            if (index < m) {
                str.push_back(word2[index]);
            }
        }
        return str;
    }
};