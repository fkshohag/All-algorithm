/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/group-shifted-strings/solution/
 */

# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <unordered_map>

# define pb push_back

using namespace std;

class Solution {
public:
    char shiftLetter(char letter, int shift) {
        return (letter - shift + 26) % 26 + 'a';
    }
    
    string generateHashKey(string s) {
        int shift = s[0];
        string hashKey;
        
        for (int index = 0; index < s.size(); index++) {
            hashKey += shiftLetter(s[index], shift);
        }
        return hashKey;
    }
    
    vector<vector<string> > groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string> > mapHashToList;
        
        for (int index = 0; index < strings.size(); index++) {
            string hashKey = generateHashKey(strings[index]);
            mapHashToList[hashKey].push_back(strings[index]);
        }
        
        vector<vector<string> > groups;
        for (auto it: mapHashToList) {
            groups.push_back(it.second);
        }
        return groups;
    }
};

int main() {
    // ["abc","bcd","acef","xyz","az","ba","a","z"]
    vector <string> v;
    v.pb("abc");   
}