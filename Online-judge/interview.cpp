# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for (int col = 0; col < strs[0].size(); col++) {
            for (int row = 1; row < strs.size(); row++) {
                if (strs[row][col] < strs[row-1][col]) {
                    ans++;
                    break;
                }
            }
        } 
        return ans;
    }
};


int main() {
    Solution s;
    vector<string> v;
    v.push_back("zyx");
    v.push_back("wvu");
    v.push_back("tsr");
    int ans = s.minDeletionSize(v);
    printf("%d", ans);
}