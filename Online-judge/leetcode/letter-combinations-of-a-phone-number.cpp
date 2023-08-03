# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 * time complexity O(m^n.n) m = 4 for 9 and 7 number digit
 * space complexity (n)
*/


class Solution {
private:
    unordered_map<int, string> digitVsChar;
    vector<string> ans;

    void solve(int idx, string& digits, string& temp) {
        if (idx == digits.size()){
            if (temp.size()) ans.push_back(temp);
        }
        int num =  digits[idx] - '0';
        string str = digitVsChar[num];

        for (int i = 0; i < str.size(); i++) {
            temp.push_back(str[i]);
            solve(idx + 1, digits, temp);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        digitVsChar = {
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, 
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"},
        };
        
        string temp;
        solve(0, digits, temp);
        return ans;
    }
};