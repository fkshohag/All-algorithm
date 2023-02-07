#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/fruit-into-baskets/description/
 * Time complexity: O(n) n is the length of fruits.
 * Space complexity: O(n) 
 */



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0, ans = 0;
        unordered_map<int, int> mp;

        while (j < fruits.size()) {
            mp[fruits[j]]++;
            // Checking basket size
            while(mp.size() > 2) {
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};