# include <bits/stdc++.h>
using namespace std;

/**
* Time complexity O(m.n + nlogn) sort = O(nlogn)
* Space complexity O(n)
*/
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for (int query : queries) {
            int count = 0;
            for (int num : nums) {
                if (query >= num) {
                    query -= num;
                    count++;
                } else {
                    break;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

/**
* Time complexity O((m+n)*logn) sort = O(nlogn), search O(mlogn) binary search
* Space complexity O(n)
*/
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int>ans;

        for (int index = 1; index < nums.size(); index++) {
            nums[index] += nums[index - 1];
        }
        for (int query : queries) {
            int index = upper_bound(nums.begin(), nums.end(), query) - nums.begin();
            ans.push_back(index);
        }
        return ans;
    }
};