# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 * Time complexity: O(n . a . b - (a . b) ^ 2)O(n⋅a⋅b−(a⋅b) ^ 2 )
 */

class Solution {
private:
    unordered_map<string, int>wordFrequency;
    int wordsSize;
    int wSize;
    int subStringSize;
    
    bool isValidSubString(unordered_map<string, int>wf, int currentIndex, string s) {
        int matchSize = 0;
        for (int index = currentIndex; index < currentIndex + subStringSize; index += wSize) {
            string sub = s.substr(index, wSize);
            if (wf.find(sub) != wf.end() && wf[sub] != 0) {
                wf[sub]--;
                matchSize++;
            }
            else {
                break;
            }
        }
        return wordsSize == matchSize;
    }
    
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        wordsSize = words.size();
        wSize = words[0].size();
        subStringSize = wordsSize * wSize;
        
        for (string word : words) {
            wordFrequency[word]++;
        }
        
        vector<int>ans;
        
        for (int index = 0; index < s.size() - subStringSize + 1; index++) {
            if (isValidSubString(wordFrequency, index, s)) {
                ans.push_back(index);
            } 
        }
        return ans;
    }
};