#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/course-schedule/
 * Time complexity: {O}(E + V)O(E+V).
 * Space complexity: {O}(E + V)O(E+V).
 */

class Solution {
private:
    bool isCyle(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& visiting, int node) {
        visited[node] = true;
        visiting[node] = true;

        for (int child: graph[node]) {
            if (!visited[child]) {
                if(isCyle(graph, visited, visiting, child)) return true;
            } else {
                if (visiting[child]) return true;
            }
        }

        visiting[node] = false;
        return false;
    }

    bool isCyleAlternativeWay(vector<vector<int>>& graph, vector<int>& visited, int node) {
        if (visited[node] == 1) return true;
        
        if (!visited[node]) {
            visited[node] = 1;
            for (int i = 0; i < graph[node].size(); i++) {
                if(isCyle(graph, visited, graph[node][i])) return true;
            }
        }

        visited[node] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &prerequisite: prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        vector<bool> visited(numCourses, false), visiting(numCourses, false);
        // vector<int> visited(numCourses, 0) alternative way
        
        for (int course = 0; course < numCourses; course++) {
            if (!visited[course]) {
                if (isCyle(graph, visited, visiting, course)) return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>inDegree(numCourses, 0);
        
        for (auto &prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }
        
        queue<int> Q;
        int takenCourse = 0;
        
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
               Q.push(i); 
            }
        }
        
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            ++takenCourse;
            
            for (auto &v : graph[u]) {
                if (--inDegree[v] == 0) {
                    Q.push(v);
                }
            }
        }
        return numCourses == takenCourse;
    }
};