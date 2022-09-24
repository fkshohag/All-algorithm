# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/reverse-linked-list/
 * O(n)
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head && head->next == nullptr) return head;
        
        ListNode* reverseNode = nullptr;
        ListNode* nextNode = nullptr;
        
        while (head) {
            nextNode = head->next;
            head->next = reverseNode;
            reverseNode = head;
            head = nextNode;
        }
        return reverseNode;
    }
};