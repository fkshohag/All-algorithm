# include <iostream>
# include <cstdio>
# include <map>
# include <vector>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-and-replace-pattern/
 */

class Solution {
public:
    
    string patternWord(string word) {
        string ans;
        int index = 0;
        map<char, char> mp;
        
        for (int i = 0; i < word.size(); i++) {
            if (mp.find(word[i]) == mp.end()) {
                mp[word[i]] = 'a' + index;
                ans.push_back(mp[word[i]]);
                index++;
            }
            else {
                ans.push_back(mp[word[i]]);
            }
        }
        return ans;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        if (pattern.size() == 0) return ans;
        string p = patternWord(pattern);
        
        for (int index = 0; index < words.size(); index++) {
            string pWord = patternWord(words[index]);
            if (pWord == p) {
                ans.push_back(words[index]);
            }
        }
        return ans;
    }
};


/*
[a] = m
[b] = e
[b] = e

[a] = 
*/