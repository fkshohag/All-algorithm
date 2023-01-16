/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/two-sum/
 * O(n)
 */



# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <map>

using namespace std;

/**
 * @brief 
 * Time complexity O(n^2)
 * Space complexity O(1);
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for (int i = 0 ; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        return v;
    }
};

/**
 * @brief 
 * Time complexity O(N)
 * Space complexity O(N)
 */
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int, int> mp;
        for (int index = 0; index < nums.size(); index++) {
            if (mp.find(target - nums[index]) == mp.end()) {
                mp[nums[index]] = index;
            } else {
                v.push_back(index);
                v.push_back(mp[target - nums[index]]);
                break;
            }
        }
        return v;
    }
};