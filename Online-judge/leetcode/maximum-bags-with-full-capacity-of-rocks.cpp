# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/
 * Time complexity O(NlogN) sorting taking this time
 * Space complexity O(N)
*/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> remaining(capacity.size(), 0);
        for (int index = 0; index < capacity.size(); index++) {
            remaining[index] = capacity[index] - rocks[index];
        }

        sort(remaining.begin(), remaining.end());
        int fullBag = 0;
        for (int index = 0; index < remaining.size(); index++) {
            if (additionalRocks >= remaining[index]) {
                additionalRocks -= remaining[index];
                fullBag++;
            } else {
                break;
            }
        }
        return fullBag;
    }
};