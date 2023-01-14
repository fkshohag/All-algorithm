# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/
 * Time complexity  O(N)
 * Space complexity O(N)
*/

class Solution {
private:
    int longestPathNode;
    int dfs(int node , vector<vector<int>>& tree, string& s) {
        int firstChild = 0, secondChild = 0;
        for (int childNode : tree[node]) {
            int startingFromChild = dfs(childNode, tree, s);
            
            if (s[childNode] == s[node]) continue;
            if (startingFromChild > firstChild) {
                secondChild = firstChild;
                firstChild = startingFromChild;
            } else {
                secondChild = max(startingFromChild, secondChild);
            }
        }
        longestPathNode = max(longestPathNode, firstChild + secondChild + 1);
        return firstChild + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> tree(n);
        for (int node = 1; node < n; node++) {
            tree[parent[node]].push_back(node);
        }
        longestPathNode = 0;
        dfs(0, tree, s);
        return longestPathNode;
    }
};