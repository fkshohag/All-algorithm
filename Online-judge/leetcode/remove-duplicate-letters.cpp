#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/remove-duplicate-letters
 * T.C: O(n)
 * S.C: O(n)
 */


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastPosition(26, 0);
        for (int i = 0; i < s.size(); i++) {
            lastPosition[s[i] - 'a'] = i; 
        }

        vector<bool> seen(26, false);
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            int key = s[i] - 'a';
            if (seen[key]) continue;
            while (st.size() > 0 && st.top() > s[i] && i < lastPosition[st.top() - 'a']) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[key] = true;
        }

        string ans = "";
        while (st.size() > 0) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }   
};