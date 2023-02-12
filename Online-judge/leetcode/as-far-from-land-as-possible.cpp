#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/as-far-from-land-as-possible/description/
 * Time complexity: O(n^2) n
 * Space complexity: O(n^2) 
 */

typedef pair<int, int> p;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<p> Q;
        vector<vector<bool>> visited(grid.size(), vector(grid[0].size(), false));

        for (int i = 0 ; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    Q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int ans = -1;
        vector<p> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!Q.empty()) {
            ans++;
            int qSize = Q.size();
            for (int i = 0; i < qSize; i++) {
                auto [x, y] = Q.front();
                Q.pop();

                for (auto& [dx, dy] : direction) {
                    int xx = x + dx;
                    int yy = y + dy;
                    if (xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[0].size() && !visited[xx][yy]) {
                        visited[xx][yy] = true;
                        Q.push({xx ,yy});
                    }
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};