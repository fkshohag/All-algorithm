# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/
 * Time complexity: O(mlogm + nlogm) = logm * (m + n) = O((m + n) * logm)
 * Space complexity: O(m) sorting space but we are not considering pair vector as a extra space
 */

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> pairs(spells.size(), 0);
        
        for (int index = 0; index < spells.size(); index++) {
            int left = 0, right = potions.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                long long product = spells[index] * potions[mid];
                if (product >= success) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            pairs[index] = (potions.size() - left);
        }
        return pairs;
    }
};