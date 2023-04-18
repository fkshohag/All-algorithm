#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-anagram-mappings/description/
 */

/**
 * @brief 
 * Time complexity : O(n)
 * Space complexity: O(n)
 */

class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mapping;
        for (int index = 0; index < nums2.size(); index++) {
            mapping[nums2[index]] = index;
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mapping[num]);
        }
        return ans;
    }
};