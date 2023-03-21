# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/can-place-flowers/description/
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int index = 0; index < flowerbed.size(); index++) {
            if (flowerbed[index] == 0) {

                bool leftIndex = (index == 0 || flowerbed[index - 1] == 0);
                bool rightIndex = (index == flowerbed.size() - 1 || flowerbed[index + 1] == 0);

                if (leftIndex && rightIndex) {
                    flowerbed[index] = 1;
                    count++;
                }
                
                if (count >= n) return true;
            }
        }
        return count >= n;
    }
};