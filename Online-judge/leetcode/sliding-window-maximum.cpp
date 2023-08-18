#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/sliding-window-maximum/
 * Complexity: running O(nlogn)
 * Space complexity: O(k)
 */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
            if (i >= (k - 1)) {
                while (i - pq.top().second >= k) {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};