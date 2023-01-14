# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/
 * Time complexity  O((N+M)log∣Σ∣)
 * Space complexity O(∣Σ∣)
*/

class Solution {
private:
    array<int, 26> representative;
    char find(int x) {
        if (representative[x] == x) return representative[x];
        return representative[x] = find(representative[x]);
    }
    void makeRepresentative(int a , int b) {
        int x = find(a);
        int y = find(b);
        if (x == y) return;
        if (x < y) representative[y] = x;
        else representative[x] = y;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans;
        for (int i = 0; i < 26; i++) {
            representative[i] = i;;
        }
        for (int index = 0; index < s1.size(); index++) {
            makeRepresentative(s1[index] - 'a', s2[index] - 'a');
        }
        for (char ch : baseStr) {
            ans += (char) find(ch - 'a') + 'a';
        }
        return ans;
    }
};