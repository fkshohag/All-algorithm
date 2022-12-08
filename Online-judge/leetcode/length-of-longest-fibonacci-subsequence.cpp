#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
 * Time complexity: O(N^2*logM). M = maximum value of arr
 * Space complexity: O(N) 
 */


class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        int ans = 0;
        int N = arr.size();

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int a = arr[i], b = arr[j], l = 2;
                while (s.count(a + b)) {
                    b = a + b, a = b - a, l++;
                }
                ans = max(ans, l);
            }
        }
        return ans > 2 ? ans : 0;
    }
};