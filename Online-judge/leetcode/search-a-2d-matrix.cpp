#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/search-a-2d-matrix/description/
 */

/**
 * @brief 
 * Time complexity : O(m * log(n))
 * Space complexity: O(1)
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int row = 0; row < matrix.size(); row++) {
            int left = 0, right = matrix[0].size() - 1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[row][mid] == target) return true;
                else if (target < matrix[row][mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
};