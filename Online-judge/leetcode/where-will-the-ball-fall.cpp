# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/where-will-the-ball-fall/
 * Time complexity: O(M⋅N) 
 * Space complexity: O(M)
 */


class Solution {
private:
    int solve(vector<vector<int>>& grid, int row, int col) {
        if (row == grid.size()) {
            return col; 
        }
        int newCol = col + grid[row][col];
        if (newCol < 0 || newCol >= grid[0].size() || grid[row][col] != grid[row][newCol]) {
            return -1;
        }
        return solve(grid, row+1, newCol);
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), 0);
        for (int i = 0; i < grid[0].size(); i++) {
            ans[i] = solve(grid, 0, i);
        }
        return ans;
    }
};

 // Time complexity: O(M⋅N) 
 // O(1)
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(), 0);
        for (int col = 0; col < grid[0].size(); col++) {
            int currentCol = col;
            for (int row = 0; row < grid.size(); row++) {
                int nextCol = currentCol + grid[row][currentCol];
                if (nextCol < 0 || nextCol >= grid[0].size() || grid[row][currentCol] != grid[row][nextCol]) {
                    ans[col] = -1;
                    break;
                }
                currentCol = nextCol;
                ans[col] = nextCol;
            }
        }
        return ans;
    }
};