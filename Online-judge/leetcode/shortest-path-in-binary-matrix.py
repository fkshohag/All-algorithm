'''
Author: <Shohag> shohag.fks@gmail.com
Problem: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
Time complexity: O(N^2)
Space complexity: O(N^2)
'''

class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        n = len(grid)
        
        if grid[0][0] or grid[n - 1][n - 1]:
            return -1
        queue = [(0, 0, 1)]
        grid[0][0] = 1

        for row, col, distance in queue:
            if row == n - 1 and col == n - 1:
                return distance
            
            directions = [
                (row, col + 1), (row, col - 1),
                (row - 1, col), (row + 1, col),
                (row - 1, col - 1), (row - 1, col + 1),
                (row + 1, col - 1), (row + 1, col + 1)
            ]

            for x, y in directions:
                if 0 <= x < n and 0 <= y <n and not grid[x][y]:
                    grid[x][y] = 1
                    queue.append((x, y, distance+1))
        return -1