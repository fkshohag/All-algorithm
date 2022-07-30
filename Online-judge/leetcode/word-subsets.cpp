# include <bits/stdc++.h>

using namespace std;


/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/word-subsets/
 * Time Complexity for this soltuion is : O(M + N) where m and n is size of words1 and words2 array
 * Explanation: https://leetcode.com/problems/word-subsets/discuss/2353065/C%2B%2B-Solution-Explained-oror-Easy-Understanding-oror-Hashing-oror-strings-oror-Commented-Code
 */

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int word2Counter[26] = {0};
        vector<string> ans;
        
        for (string &word : words2) {
            int wordCounter[26] = {0};
            for (int index = 0; index < word.size(); index++) {
                wordCounter[word[index] - 'a']++;
                word2Counter[word[index] - 'a'] = max(word2Counter[word[index] - 'a'], wordCounter[word[index] - 'a']);
            }
        }
        
        for (string &word : words1) {
            int wordCounter[26] = {0};
            for (int index = 0; index < word.size(); index++) {
                wordCounter[word[index] - 'a']++;
            }
            
            bool isSubset = true;
            for (int index = 0; index < 26; index++) {
                if (wordCounter[index] < word2Counter[index]) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};