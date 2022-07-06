# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/merge-sorted-array/
 * O(n)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ans[m+n];
        int i = 0, j = 0, index = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                ans[index++] = nums1[i];
                i++;
            } else {
                ans[index++] = nums2[j];
                j++;
            }
        }
        while (i < m) {
            ans[index++] = nums1[i];
            i++;
        }
        while (j < n) {
            ans[index++] = nums2[j];
            j++;
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = ans[i];
        }
    }
};