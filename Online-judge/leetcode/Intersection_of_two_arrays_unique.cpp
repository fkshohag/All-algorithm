# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/intersection-of-two-arrays/
 * O(n)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>frequency;
        set<int, greater<int> > s;
        vector<int>ans;
        for (int i = 0; i < nums1.size(); i++){
            frequency[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (frequency[nums2[i]] > 0) {
                s.insert(nums2[i]);
                frequency[nums2[i]]--;
            }
        }
        set<int, greater<int> >::iterator itr;
        for (itr = s.begin(); itr != s.end(); itr++) {
            ans.push_back(*itr);
        }
        return ans;
    }
};