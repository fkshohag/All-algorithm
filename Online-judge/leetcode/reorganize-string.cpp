#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/reorganize-string/submissions/
 * T.C: O(N*logK) N = string length, K unique character
 * S.C: O(K)
 */

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        priority_queue<vector<int>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], i + 'a'});
            }
        }

        string ans;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (!ans.size() || ans.back() != top[1]) {
                ans.push_back(top[1]);
                if (--top[0] > 0) {
                    pq.push(top);
                }
            } else {
                if (pq.empty()) return "";
                auto secondTop = pq.top();
                pq.pop();
                ans.push_back(secondTop[1]);
                if (--secondTop[0] > 0) {
                    pq.push(secondTop);
                }
                pq.push(top);
            }
        }
        return ans;
    }
};