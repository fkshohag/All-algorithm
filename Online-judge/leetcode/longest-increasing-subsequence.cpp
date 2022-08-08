# include <iostream>
# include <cstdio>
# include <vector>

using namespace std;


/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/longest-increasing-subsequence/
 */

// Running complexity n^2 worst case

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>sub;
        sub.push_back(nums[0]);
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > sub[sub.size() - 1]) {
                sub.push_back(nums[i]);
            }
            else {
                int j = 0;
                while (nums[i] > sub[j]) {
                    j++;
                }
                sub[j] = nums[i];
            }
        }
        return sub.size();
    }
};


// Running complexity O (n log(n)) worst case

class Solution {
private: 
    int binarySearch(vector<int>& sub, int target) {
        int left = 0, right = sub.size() - 1, mid;
        
        while (left < right) {
            mid = (left + right) / 2;
            if (sub[mid] == target) {
                return mid;
            }
            if (target < sub[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>sub;
        sub.push_back(nums[0]);
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > sub[sub.size()-1]) {
                sub.push_back(nums[i]);
            }
            else {
                int index = binarySearch(sub, nums[i]);
                sub[index] = nums[i];
            }
        }
        return sub.size();
    }
};


