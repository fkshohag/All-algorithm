#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/course-schedule-ii/
 * Time complexity: {O}(E + V)O(E+V).
 * Space complexity: {O}(E + V)O(E+V).
 */


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>inDegree(numCourses, 0);
        
        for (auto &prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }
        
        queue<int> Q;
        vector<int>ans;
        
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                Q.push(i);
                ans.push_back(i);
            }
        }
        
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            
            for (auto &v : graph[u]) {
                if (--inDegree[v] == 0) {
                    Q.push(v);
                    ans.push_back(v);
                }
            }
        }
        if(ans.size() < numCourses) return {};
        return ans;
    }
};