# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/confusing-number/description/
 * Time complexity: O(n)
 * Space complexity: O(1)
*/

/**
 * @brief 
 * 
 */
class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<char, char> rotatedNumbers = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        string number;

        for (char digit : to_string(n)) {
            if (rotatedNumbers.find(digit) == rotatedNumbers.end()) return false;
            number.push_back(rotatedNumbers[digit]);
        }
        
        reverse(number.begin(), number.end());
        return stoi(number) == n ? false : true;
    }
};