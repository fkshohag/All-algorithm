# include<iostream>
# include <cstring>
# include <map>
# include <unordered_map>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/first-unique-character-in-a-string/
 */

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int>frequency;
        for (int i = 0; i < s.length(); i++) {
            if (frequency.find(s[i]) == frequency.end()) {
                frequency[s[i]] = 1;
            }
            else {
                frequency[s[i]] += 1;
            }
        }
        for (int i = 0 ; i < s.length(); i++) {
            if(frequency[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         int frequency[26];
//         for (int index = 0; index < s.length(); index++) {
//             int key = s[index] - 'a';
//             frequency[key]++;
//         }
        
//         for (int index = 0; index < s.length(); index++) {
//             int key = s[index] - 'a';
//             if (frequency[key] == 1) {
//                 return index;
//             }
//         }
//         return -1;
//     }
// };