/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/string-to-integer-atoi/
 */



# include <iostream>
# include <cstring>
# include <cstdio>
# include <climits>


using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long number = 0;
        int len = s.size();
        int index = 0;
        
        while (index < len && s[index] == ' ') {
            index++;
        }
        
        if(index < len && s[index] == '-') {
            sign *= -1;
            index++;
        } else if (index < len && s[index] == '+') {
            sign *= 1;
            index++;
        }
        
        while (index < len && isdigit(s[index])) {
            int digit = s[index] - '0';
            number = (number * 10) + digit;

            if (number > INT_MAX) {
                if (sign) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            index++;
        }
        
        return sign * number;
    }
};


int main() {

}