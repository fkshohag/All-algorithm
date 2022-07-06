/*
 @author Md.Shohag <shohag.fks@gmail.com>
 Problem : https://leetcode.com/problems/roman-to-integer/submissions/
 O(n)
*/

class Solution {
public:
    unordered_map<char, int>symbolValue = {
        {'I', 1}, 
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int romanToInt(string s) {
        int index = 0;
        int number = 0;
        while (index < s.size()) {
            if (index + 1 < s.size() && symbolValue[s[index]] < symbolValue[s[index + 1]]) {
                number += symbolValue[s[index + 1]] - symbolValue[s[index]];
                index += 2;
            } else {
                number += symbolValue[s[index]];
                index++;
            }
        }
        return number;
    }
};