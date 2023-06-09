# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-smallest-letter-greater-than-target/
 */


/**
 * @brief 
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char letter : letters) {
            if (letter > target) {
                return letter;
            }
        }
        return letters[0];
    }
};

/**
 * @brief 
 * Time complexity: O(log(N))
 * Space complexity: O(1)
 */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0 , right = letters.size() - 1, mid;
        
        while (left <= right) {
            mid = (right + left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left == letters.size() ? letters[0] : letters[left];
    }
};