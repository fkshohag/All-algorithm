# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * O(n)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            intersect(nums2 , nums1);
        }
        unordered_map<int, int>frequency;
        vector<int>ans;
        for (int i = 0; i < nums1.size(); i++){
            frequency[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (frequency[nums2[i]] > 0) {
                ans.push_back(nums2[i]);
                frequency[nums2[i]]--;
            }
        }
        return ans;
    }
};