# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/palindrome-linked-list/description/
 * Time complexity  O(n)
 * Space complexity O(n)
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* currentNode = head;
        vector<int> v;
        while(currentNode) {
            v.push_back(currentNode->val);
            currentNode = currentNode->next;
        }
        for (int i = 0, j = v.size()-1; i <= j; i++, j--) {
            if (v[i] != v[j]) return false;
        }
        return true;
    }
};