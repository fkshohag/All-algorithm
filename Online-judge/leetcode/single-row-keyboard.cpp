/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/single-row-keyboard/description/
 * Time complexity O(n)
 * Space complexity O(n)
 * 
 */


class Solution {
public:
    int calculateTime(string keyboard, string word) {
       unordered_map<char, int> keyMap;
       for (int i = 0; i < keyboard.size(); i++) {
           keyMap[keyboard[i]] = i;
       }  

       int time = 0, lastKey = 0;
       for (int i = 0; i < word.size(); i++) {
           time += abs(keyMap[word[i]] - lastKey);
           lastKey = keyMap[word[i]];
       }
       return time;
    }
};