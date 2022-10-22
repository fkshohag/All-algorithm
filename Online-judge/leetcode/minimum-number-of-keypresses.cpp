# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-number-of-keypresses/
 * Solution: https://leetcode.com/problems/minimum-number-of-keypresses/discuss/2432518/Simple-C%2B%2B-solution-explained-with-O(n)-time-complexity-explained
 * Time Complexity: O(N)
 * Space Constand
 */


class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> frequency(26, 0);
        for (int i = 0 ; i < s.size(); i++) {
            frequency[s[i] - 'a']++;
        }
        sort(frequency.rbegin(), frequency.rend());
        int count = 0;
        for (int i = 0; i < 26; i++) {
            count += frequency[i] * (i / 9 + 1);
        }
        return count;
    }
};