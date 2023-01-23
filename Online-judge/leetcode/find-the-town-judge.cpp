# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/find-the-town-judge/description/
 * Time complexity  O(n)
 * Space complexity O(n)
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1);
        vector<int> outdegree(n+1);
        for (int index = 0; index < trust.size(); index++) {
            outdegree[trust[index][0]]++;
            indegree[trust[index][1]]++;
        }

        int ans = -1;
        for (int index = 1; index <= n; index++) {
            if (outdegree[index] == 0 && indegree[index] == n-1) {
                ans = index;
                break;
            }
        }
        return ans;
    }
};