# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
 * Running complexity O(n)
 * Memory complexity O(1)
*/



class Solution {
private:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
        return false;
    }

public:
    bool halvesAreAlike(string s) {
        int aNumberOfVowel = 0, bNumberOfVowel = 0;
        int mid = s.size() / 2;
        int i = 0, j = mid;
        while (i < mid) {
            if (isVowel(s[i])) {
                aNumberOfVowel++;
            }
            if (isVowel(s[j])) {
                bNumberOfVowel++;
            }
            i++;
            j++;
        }
        if (aNumberOfVowel == bNumberOfVowel) return true;
        return false; 
    }
};