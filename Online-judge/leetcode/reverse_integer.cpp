/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/reverse-integer/
 */



# include <iostream>
# include <cstdio>
# include <cstring>
# include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int number = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (number > INT_MAX / 10 || (digit == INT_MAX / 10  && digit > 7)) return 0;
            if (number < INT_MIN / 10 || (digit == INT_MIN && digit < - 8) ) return 0;
            number = 10 * number + digit;
        }
        return number;
    }
};

int main() {

}