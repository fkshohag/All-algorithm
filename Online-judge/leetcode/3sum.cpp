# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/3sum/description/
 * Time complexity  O(n^2) sorting O(nlogn) 
 * Space complexity O(logn) to O(n)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3) return {};
        vector<vector<int>> ans;
        if (nums[0] > 0) return {};
        
        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] > 0) break;
            if (index > 0 && nums[index] == nums[index - 1]) continue;
            int low = index+1, high = nums.size() - 1;

            int sum = 0;
            while (low < high) {
                sum = nums[index] + nums[low] + nums[high];
                if (sum < 0) {
                    low++;
                } else if (sum > 0) {
                    high--;
                }  else {
                    ans.push_back({nums[index], nums[low], nums[high]});
                    int lastLow = nums[low], lastHigh = nums[high];
                    while (low < high && nums[low] == lastLow) {
                        low++;
                    }
                    while (low < high && nums[high] == lastHigh) {
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};