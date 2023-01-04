# include <bits/stdc++.h>
using namespace std;

/*
7 count of 2
3, 2, 2 group
1, 2, 3 counter
7/3 = 2+1 = 3

8 count of 2
3, 3, 2 group
1, 2, 3 counter
8/3 = 2+1 = 3
*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int>freq;
        for (int task : tasks) {
            freq[task]++;
        }
        
        int rounds = 0;
        for (auto [task, count] : freq) {
            if (count == 1) return -1;
            if (count % 3 == 0) {
                rounds += count / 3;
            } else {
                rounds += count / 3 + 1;
            }
        }
        return rounds;
    }
};
