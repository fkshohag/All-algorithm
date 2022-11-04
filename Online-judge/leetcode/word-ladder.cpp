# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/word-ladder/
 * Time complexity O(26 * length of beginWord * number of words in wordList)
 * Space Complexity O(n + n) or O(n).
*/



class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> dist(wordList.begin(), wordList.end()), seen;
        q.push(beginWord);
        seen.insert(beginWord);

        int steps = 0;
        while (!q.empty()) {
            int wordInQueue = q.size();
            steps++;
            for (int j = 0; j < wordInQueue; j++) {
                string word = q.front();
                q.pop();
                
                if (word == endWord) {
                    return steps;
                }
                for (int i = 0; i < word.size(); i++) {
                    char reserve = word[i];
                    for (int k = 0; k < 26; k++) {
                        word[i] = 'a' + k;
                        if (dist.count(word) && !seen.count(word) ) {
                            q.push(word);
                            seen.insert(word);
                        }
                    }
                    word[i] = reserve;
                }
            }
        }
        return 0;
    }
};