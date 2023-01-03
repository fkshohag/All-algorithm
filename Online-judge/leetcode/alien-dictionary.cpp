# include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 */

class Solution {
private:
    bool storeGraph(vector<string>& words, unordered_map<char, unordered_set<char>>& graph, unordered_map<char, int>& inDegree) {
        for (int index = 0; index < words.size() - 1; index++) {
            string a = words[index], b = words[index + 1];
            int len = min(a.size(), b.size());

            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {
                    unordered_set<char> set = graph[a[j]];
                    if (set.find(b[j]) == set.end()) {
                        graph[a[j]].insert(b[j]);
                        inDegree[b[j]]++;
                    }
                    break;
                }
                if (j == len - 1 && a.size() > b.size()) return false;
            }
        }
        return true;
    }

    string topologicalSort(unordered_map<char, unordered_set<char>>& graph, unordered_map<char, int>& inDegree) {
        string ans;
        queue<char> Q;
        for (auto& e : inDegree) {
            if (e.second == 0) {
                Q.push(e.first);
            }
        }

        while(!Q.empty()) {
            char cur = Q.front();
            Q.pop();
            ans += cur;
            if (graph[cur].size()) {
                for (auto& e : graph[cur]) {
                    inDegree[e]--;
                    if (inDegree[e] == 0) {
                        Q.push(e);
                    }
                }
            }
        }
        return ans.size() == inDegree.size() ? ans : "";
    }

public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> inDegree;
        unordered_map<char, unordered_set<char>> graph;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char ch = words[i][j];
                inDegree[ch] = 0;
            }
        }
        if (!storeGraph(words, graph, inDegree)) {
            return "";
        }
        return topologicalSort(graph, inDegree);
    }
};