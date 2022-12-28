# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/
 * Time complexity O(n+klogn) each heap operation cost O(logn)
 * Space complexity O(n)
*/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> mxHeap(piles.begin(), piles.end());
        int sum = accumulate(piles.begin(), piles.end(), 0);

        for (int i = 0; i < k; i++) {
            int top = mxHeap.top();
            mxHeap.pop();
            int remove = top / 2;
            sum -= remove;
            mxHeap.push(top - remove);
        }
        return sum;
    }
};