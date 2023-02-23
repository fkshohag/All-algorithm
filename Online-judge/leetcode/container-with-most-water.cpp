#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/container-with-most-water/description/
 */

/**
 * @brief 
 * Time complexity : O(n^2)
 * Space complexity: O(1)
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0;
        for (int left = 0; left < height.size(); left++) {
            for (int right = left + 1; right < height.size(); right++) {
                int currentArea = min(height[left], height[right]) * (right - left);
                mx = max(mx, currentArea);
            }
        }
        return mx;
    }
};

/**
 * @brief 
 * Time complexity : O(n)
 * Space complexity: O(1)
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0, left = 0, right = height.size() - 1;

        while (left <= right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            mx = max(mx, currentArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return mx;
    }
};