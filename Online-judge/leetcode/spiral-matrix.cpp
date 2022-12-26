# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/spiral-matrix/description/
 * Time complexity O(n)
 * Space complexity O(n)
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        if (m == 0) return ans;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, d = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m * n; i++) {
            ans.push_back(matrix[x][y]);
            visited[x][y] = true;
            int xx = x + dx[d];
            int yy = y + dy[d];

            if (xx >= 0 && xx < m &&  yy >= 0 && yy < n && !visited[xx][yy]) {
                x = xx;
                y = yy;
            } else {
                d = (d + 1) % 4;
                x += dx[d];
                y += dy[d];
            }
        }
        return ans;
    }
};