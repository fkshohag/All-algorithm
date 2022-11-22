#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/perfect-squares/description/
 * Running complexity O(n*log(log(n)))
 * Memory complexity O(n)
 */

class Solution {
public:
    int countPrimes(int n) {
        vector<bool>prime(n+1, true);
        prime[0] = false;
        prime[1] = false;

        for (int i = 2; i*i <= n; i++) {
            if (prime[i]) {
                for (int j = i*i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
            }
        }
        return count;
    }
};