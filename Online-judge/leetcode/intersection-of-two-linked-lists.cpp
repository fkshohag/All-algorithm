# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/intersection-of-two-linked-lists/
 * O(n)
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        
        int m = 0, n = 0;
        ListNode* currentNode = headA;
        while(currentNode) {
            m++;
            currentNode = currentNode->next;
        }
        
        currentNode = headB;
        while (currentNode) {
            n++;
            currentNode = currentNode->next;
        }
        int skipNodes = 0, counter = 0;
        
        if (m > n) {
            skipNodes = m - n;
            while (headA) {
                counter++;
                headA = headA->next;
                if(counter == skipNodes) {
                    break;
                }
            }
        }
        else if (n > m) {
            skipNodes = n - m;
            while (headB) {
                counter++;
                headB = headB->next;
                if(counter == skipNodes) {
                    break;
                }
            }
        }
        while(headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};