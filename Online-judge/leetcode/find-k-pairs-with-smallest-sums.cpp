#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 * Time complexity O(n1*n2*logk)
 * Space Complexity O(k)
 */

typedef pair<int, int> p;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, p>> pq;
        vector<vector<int>> ans;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];

                if (pq.size() < k) {
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else if (sum < pq.top().first) {
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else if(sum > pq.top().first) {
                    break;
                }
            }
        }
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ans.push_back({top.second.first, top.second.second});
        }
        return ans;
    }
};