from typing import List

'''
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
'''

'''
 * Time complexity: O(n^2).
 * Space complexity: O(1)
'''
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        for row in grid:
            for value in row:
                if value < 0:
                    count += 1
        return count

'''
 Binary search
 * Time complexity: O(mlogn).
 * Space complexity: O(1)
'''
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        n = len(grid[0])
        # Trying to find out first negative number
        for row in grid:
            left, right = 0, n - 1
            while left <= right:
                mid = (right + left) // 2
                if row[mid] < 0:
                    right = mid - 1
                else:
                    left = mid + 1
            count += (n - left)
        return count