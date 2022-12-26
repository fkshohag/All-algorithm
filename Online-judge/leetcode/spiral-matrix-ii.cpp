# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/spiral-matrix-ii/description/
 * Time complexity O(n)
 * Space complexity O(n*n)
*/

class Solution {
private:
    int N;
    vector<vector<int>> solve() {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int x = 0, y = 0, d = 0;
        vector<vector<int>> matrix(N, vector<int>(N, 0));
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        
        for (int i = 1; i <= N * N; i++) {
            matrix[x][y] = i;
            visited[x][y] = true;
            int xx = x + dx[d];
            int yy = y + dy[d];

            if (xx >= 0 && xx < N && yy >= 0 && yy < N && !visited[xx][yy]) {
                x = xx;
                y = yy;
            } else {
                d = (d + 1) % 4;
                x += dx[d];
                y += dy[d]; 
            }
        }
        return matrix;
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        N = n;
        return solve();
    }
};