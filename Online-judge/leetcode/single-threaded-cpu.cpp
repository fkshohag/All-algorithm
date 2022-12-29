# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/single-threaded-cpu/description/
 * Time complexity O(NlogN) sort taks O(NlogN)
 * Space complexity O(N)
*/


typedef pair<int, int>p;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int index = 0; index < tasks.size(); index++) {
            tasks[index].push_back(index);
        }

        priority_queue<p, vector<p>, greater<p>> remainingTask;
        sort(tasks.begin(), tasks.end());
        vector<int> ans;
        int taskIndex = 0, arrivalTime = 0;

        while (ans.size() < tasks.size()) {
            if (remainingTask.empty() && taskIndex < tasks.size()) {
                arrivalTime = max(arrivalTime, tasks[taskIndex][0]);
            }
            while (taskIndex < tasks.size() && tasks[taskIndex][0] <= arrivalTime) {
                remainingTask.push({tasks[taskIndex][1], tasks[taskIndex][2]});
                taskIndex++;
            }

            auto [processingTime, index] = remainingTask.top();
            remainingTask.pop();
            arrivalTime = min(1000000000, arrivalTime + processingTime);
            ans.push_back(index);
        }
        return ans;
    }
};