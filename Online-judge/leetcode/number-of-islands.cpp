# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/number-of-islands/description/
 * Time complexity O(M*N)
 * Memory complexity O(M*N)
*/

class Solution {
private:
    void solve(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        if (grid[row][col] == '0' || grid[row][col] == '2') return;
        
        grid[row][col] = '2';

        solve(grid, row + 1, col);
        solve(grid, row, col+1);
        solve(grid, row - 1, col);
        solve(grid, row, col-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    solve(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};