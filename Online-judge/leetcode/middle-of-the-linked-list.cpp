#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/middle-of-the-linked-list/description/
 * Time complexity: O(n).
 * Space complexity: O(1).
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int listSize(ListNode* head) {
        ListNode* ptr = head;
        int size = 0;
        while(ptr) {
            size++;
            ptr = ptr->next;
        }
        return size;
    }

public:
    ListNode* middleNode(ListNode* head) {
        int size = listSize(head);
        int mid = (size/2)+1;
        ListNode* ptr = head;
        ListNode* midNode = NULL;
        int nodeCounter = 0;

        while (ptr) {
            nodeCounter++;
            if (nodeCounter >= mid) {
                if (midNode == NULL) {
                    midNode = ptr;
                    break;
                } else {
                    midNode->next = ptr;
                    midNode = midNode->next; 
                }
            }
            ptr = ptr->next;
        }
        return midNode;
    }
};


/**
 * @brief 
 * Time complexity O(n)
 * Space Complexity O(1)
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};