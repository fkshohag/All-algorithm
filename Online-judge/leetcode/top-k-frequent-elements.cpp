#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/top-k-frequent-elements/description/
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        
        vector<int>ans;
        for (auto it : freq) {
            q.push({it.second, it.first});
        }

        while(k) {
            ans.push_back(q.top().second);
            q.pop();
            k--;
        }
        return ans;
    }
};