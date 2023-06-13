// Time complexity O(n^3)
// Space complexity O(n^1)

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        int n = (int) grid.size();
        for (int row = 0; row < n; row++) {
            vector<int> v1(grid[row]);
            vector<int> v2;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                   v2.push_back(grid[j][i]); 
                }
                if (v1 == v2) count++;
                v2.clear();
            }
        }
        return count;
    }
};