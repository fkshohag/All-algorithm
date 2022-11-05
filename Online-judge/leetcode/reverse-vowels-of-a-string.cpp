# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/reverse-vowels-of-a-string
 * Running complexity O(n)
 * Memory complexity O(1)
*/

class Solution {
private:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        int startIndex = 0, endIndex = s.length() - 1;
        while (startIndex < endIndex) {
            while(startIndex < s.size() && !isVowel(s[startIndex])) {
                startIndex++;
            }
            while(endIndex >= 0 && !isVowel(s[endIndex])) {
                endIndex--;
            }
            if (startIndex < endIndex) {
                swap(s[startIndex++], s[endIndex--]);
            }
        }
        return s;
    }
}; 