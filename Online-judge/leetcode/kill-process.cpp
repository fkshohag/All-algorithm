/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/kill-process/
 * Time complexity: O(n) no node has multiple parent that's why we tervese N node
 * Space complexity: O(n) hash mapping
*/


class Solution {
private:
    void killedProcees(int kill, map<int, set<int>> &childrens, vector<int> &ans) {
        ans.push_back(kill);
        for (int children : childrens[kill]) {
            killedProcees(children, childrens, ans);
        }
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, set<int>> childrens;
        for (int i = 0; i < pid.size(); i++) {
            childrens[ppid[i]].insert(pid[i]);
        }

        vector<int>ans;
        // dfs
        // this->killedProcees(kill, childrens, ans);
        // bfs
        queue<int> q;
        q.push(kill);
        while(!q.empty()) {
            int curr_p = q.front(); q.pop();
            ans.push_back(curr_p);
            for (int children : childrens[curr_p]) {
                q.push(children);
            }
        }
        return ans;
    }
};