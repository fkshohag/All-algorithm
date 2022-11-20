#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/encode-and-decode-strings/description/
 */


class Codec {
private:
    vector<int>lens;
public:
    string encode(vector<string>& strs) {
        string res = "";
        for (string s : strs) {
            res += s;
            lens.push_back(s.size());
        }   
        return res;
    }
    
    vector<string> decode(string s) {
        vector<string> ans;
        int pos = 0;
        for (int i = 0; i < lens.size(); i++) {
            ans.push_back(s.substr(pos, lens[i]));
            pos += lens[i];
        }
        return ans;
    }
};