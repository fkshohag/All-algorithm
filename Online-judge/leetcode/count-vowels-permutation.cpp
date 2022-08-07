# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/count-vowels-permutation/
 */


class Solution {
public:
    int countVowelPermutation(int n) {
        long aCount = 1, eCount = 1, iCount = 1, oCount = 1, uCount = 1;
        long  MOD = 1000000007;
        
        for (int i = 1; i < n; i++) {
            long  newAcount = (eCount + iCount + uCount) % MOD;
            long  newEcount = (aCount + iCount) % MOD;
            long  newIcount = (eCount + oCount) % MOD;
            long  newOcount = iCount;
            long  newUcount = (iCount + oCount) % MOD;
            aCount = newAcount;
            eCount = newEcount;
            iCount = newIcount;
            oCount = newOcount;
            uCount = newUcount;
        }
        long res = (aCount + eCount + iCount + oCount + uCount) % MOD;
        return (int) res;
    }
};