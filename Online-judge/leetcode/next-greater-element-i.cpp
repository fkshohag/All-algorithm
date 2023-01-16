# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/next-greater-element-i/description/
 * Time complexity  O(nums1.size + nums2.size)
 * Space complexity O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int index = 0; index < nums2.size(); index++) {
            mp.insert({nums2[index], index});
        }
        for (int num : nums1) {
            if (mp.find(num) == mp.end()) {
                ans.push_back(-1);
            } else {
                int index = mp[num];
                if (index >= nums2.size() - 1){
                    ans.push_back(-1);
                    continue;
                }
                else {
                    bool found = false;
                    for (int i = index + 1; i < nums2.size(); i++) {
                        if (nums2[i] > num) {
                            ans.push_back(nums2[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found) ans.push_back(-1); 
                }
            }
        }
        return ans;
    }
};