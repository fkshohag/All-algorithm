# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/sort-characters-by-frequency/description/
 */

/**
 * @brief 
 * also it takes up to s.length space. and it might be A LOT. trading O(m log(m) ) 
 * sorting time where m = 256 (i.e. small const) for O(n) time AND O(n) space.
 * Even just time might be O(n) >>>>O(m log(m))
 */

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;

        for(char ch: s) {
            freq[ch]++;
        }
        for (auto& it: freq) {
            bucket[it.second].append(it.second, it.first);
        }

        for (int i = s.size(); i > 0; i --) {
            if (!bucket[i].empty()) {
                res.append(bucket[i]);
            }
        }
        return res;
    }
};

/**
 * @brief 
 * Time complexity O(n)
 * Memory complexity (n)
 */

class Solution {
public:
    typedef pair<int, char> p;

    string frequencySort(string s) {
        unordered_map<char, int> freq;
        string res;
        for(char ch: s) {
            freq[ch]++;
        }

        priority_queue<p> pq;
        for (auto& it : freq) {
            pq.push({it.second, it.first});
        }

        while(!pq.empty()) {
            p t = pq.top();
            pq.pop();
            res.append(t.first, t.second);
        }
      
        return res;
    }
};