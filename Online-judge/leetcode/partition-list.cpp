#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/partition-list/description/
 * Complexity: running O(n)
 * Space complexity: O(1)
 */



// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


 /*
 before              x          after 
 x1 < x2 < x3 < x4 < x <= y1 <= y2 <= y3 <= y4
 1, 2, 2, 3, 4, 5
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_head = new ListNode();
        ListNode* before = before_head;
        ListNode* after_head = new ListNode();
        ListNode* after = after_head;

        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        
        after->next = NULL;
        before->next = after_head->next;
        return before_head->next;
    }
};