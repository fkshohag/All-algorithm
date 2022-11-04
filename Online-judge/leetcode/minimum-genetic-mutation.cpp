# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/minimum-genetic-mutation/
 * Time complexity: O(B), where B = bank.length.
 * Space complexity: O(1)O(1)
*/


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> seen;
        q.push(startGene);
        seen.insert(startGene);
        
        int step = 0;
        while(!q.empty()) {
            int nodeInQueue = q.size();
            for (int j = 0; j < nodeInQueue; j++) {
                string node = q.front();
                q.pop();
                
                if (node == endGene) {
                    return step; 
                }
                for (char c : "ACGT") {
                    for (int i = 0; i < node.size(); i++) {
                        string newGen = node;
                        newGen[i] = c;
                        if (!seen.count(newGen) && find(bank.begin(), bank.end(), newGen) != bank.end()) {
                            q.push(newGen);
                            seen.insert(newGen);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};