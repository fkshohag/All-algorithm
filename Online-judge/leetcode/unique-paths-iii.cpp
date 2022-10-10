/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/unique-paths-iii/
 * Time Complexity: O(3^N)
 * Space Complexity: O(N)
 */

class Solution {
private:
    int numberOfFreePath;
    int uniquePath(vector<vector<int>>& grid, int x, int y, int freePathCounter) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1) return 0;
        if (grid[x][y] == 2) return freePathCounter == numberOfFreePath ? 1 : 0;
        
        grid[x][y] = -1;
        int paths = uniquePath(grid, x+1, y, freePathCounter+1)
            + uniquePath(grid, x-1, y, freePathCounter+1)
            + uniquePath(grid, x, y+1, freePathCounter+1)
            + uniquePath(grid, x, y-1, freePathCounter+1);
        grid[x][y] = 0;
        return paths;
        
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX = 0, startY = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0 ; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] != -1) {
                    numberOfFreePath++;
                }
            }
        }
        return uniquePath(grid, startX, startY, 1);
    }
};