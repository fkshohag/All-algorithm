# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/daily-temperatures/description/
 * Time complexity : An easier way to think about this is that in the worst case, 
 * every element will be pushed and popped once. This gives a time complexity of O(2⋅N) = O(N).
 * Space complexity : O(N) 
 * answer does not count towards the space complexity because space used for the output format does not count.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int day = 0; day < n; day++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[day]) {
                int prev= st.top(); st.pop();
                ans[prev] = day - prev;
            }
            st.push(day);
        }
        return ans;
    }
};