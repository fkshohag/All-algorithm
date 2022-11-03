# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
 * Time complexity: O(N + \min(N, |\Sigma|^2))O(N+min(N,∣Σ∣ 2)).
 *  Space complexity: O(\min (N, |\Sigma|^2))O(min(N,∣Σ∣ 2)).
 */


class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> freq;
        for (string word : words) {
            freq[word]++;
        }
        
        int count = 0, oddCount = 0;
        for (const auto& [key, value] : freq) {
            if (key[0] == key[1]) {
                if (!oddCount && value % 2 == 1) {
                    oddCount++;
                }
                count += 2 * (value / 2);
            } else {
                count += 2 * min(freq[key], freq[{key[1], key[0]}]);
                freq[key] = 0;
                freq[{key[1], key[0]}] = 0;
            }
        }
        return 2 * (count + oddCount);
    }
};