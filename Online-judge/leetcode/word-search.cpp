#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/word-search/
 *Time Complexity: O(mn)
 *Space Complexity:O((word_length)^2)
 */


class Solution {
private:
    bool findWord(vector<vector<char>> &board, string &word, int i, int j, int n) {
        if (n == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[n]) return false;
        board[i][j] = '0'; // visited path
        bool status = findWord(board, word, i+1 , j, n+1) // down
            || findWord(board, word, i-1 , j, n+1) // up
            || findWord(board, word, i , j + 1, n+1) // right
            || findWord(board, word, i , j - 1, n+1); // left
            
        board[i][j] = word[n]; // free for next search 
        return status;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() < 1) return false;
    
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] & findWord(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};