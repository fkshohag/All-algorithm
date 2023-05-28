#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/
 * Time complexity O(n)
 * Space Complexity O(1)
 */

class Solution {
public:
    double average(vector<int>& salary) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        int sum = 0;

        for (int s : salary) {
            sum += s;
            if (s > mx) mx = s;
            if (s < mn) mn = s;
        }
        return (double) (sum - (mx + mn)) / (salary.size() - 2);
    }
};