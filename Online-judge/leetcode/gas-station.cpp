# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/gas-station/description/
 * Time complexity: O(n)
 * Space complexity: O(1)
*/

/**
 * @brief 
 * 
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0, totalGas = 0;
        for (int index = 0; index < gas.size(); index++) {
            totalCost += cost[index];
            totalGas += gas[index];
        }
        if (totalCost > totalGas) return -1;

        int startIndex = 0, currentGas = 0;
        for (int index = 0; index < gas.size(); index++) {
            if (currentGas < 0) {
                currentGas = 0;
                startIndex = index;
            }
            currentGas += (gas[index] - cost[index]);
        }
        return startIndex;
    }
};