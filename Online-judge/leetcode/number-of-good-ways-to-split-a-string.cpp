# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
 * Time Complexity: O(n)
 */

class Solution {
public:
    int numSplits(string s) {
        unordered_set<char> leftCount, rightCount;
        vector<int> prefix(s.length(), 0), suffix(s.length(), 0);
        
        for (int i = 0, j = s.length() - 1 ; i < s.length(); i++, j--) {
            leftCount.insert(s[i]);
            prefix[i] = leftCount.size();
            rightCount.insert(s[j]);
            suffix[j] = rightCount.size();
        }

        int ans = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (prefix[i] == suffix[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};