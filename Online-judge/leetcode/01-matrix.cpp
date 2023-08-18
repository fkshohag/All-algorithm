#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/01-matrix/description/
 * Complexity: running O(m * n)
 * Space complexity: O(m * n)
 */

class Solution {
private:
    int m, n;

    bool valid (int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> matrix (m, vector<int>(n, 0));
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        queue<vector<int>> Q;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                matrix[row][col] = mat[row][col];
                if (matrix[row][col] == 0) {
                    Q.push({row, col, 0});
                    visited[row][col] = true;
                }
            }
        }

        while (!Q.empty()) {
            vector<int> currentNode = Q.front();
            Q.pop();
            int row = currentNode[0], col = currentNode[1], distance = currentNode[2];

            for (int i = 0; i < 4; i++) {
                int xx = row + dx[i];
                int yy = col + dy[i];
                if (valid(xx, yy) && !visited[xx][yy]) {
                    visited[xx][yy] = true;
                    Q.push({xx, yy, distance + 1});
                    matrix[xx][yy] = distance + 1;
                }
            }
        }
        return matrix;
    }
};
