# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <utility>
# include <cstdlib>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/merge-two-sorted-lists
 * Running Complexity O(m+n), Space Complexity: O(m+n)
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if (list1 == nullptr) return list2;
//         else if (list2 == nullptr) return list1;
//         else if (list1->val < list2->val) {
//             list1->next = mergeTwoLists(list1->next, list2);
//             return list1;
//         }
//         else {
//             list2->next = mergeTwoLists(list1, list2->next);
//             return list2;
//         }
//     }
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* headNode = new ListNode();
        ListNode* currentNode = headNode;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                currentNode->next = list1;
                list1 = list1->next; 
            }
            else {
                currentNode->next = list2;
                list2 = list2->next;
            }
            currentNode = currentNode->next;
        }
        currentNode->next = list1 == nullptr ? list2 : list1;
        return headNode->next;
    }
};