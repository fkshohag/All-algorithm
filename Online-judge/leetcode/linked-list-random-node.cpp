#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/linked-list-random-node/description/
 */

/**
 * @brief 
 * Time complexity : O(n)
 * Space complexity: O(1)
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
    ListNode* mHead;
public:
    Solution(ListNode* head) {
        mHead = head;
    }
    
    int getRandom() {
        ListNode* curr = mHead;
        int res = 0, i = 1;
        while (curr) {
            if (rand() % i == 0) {
                res = curr->val;
            }
            i++;
            curr = curr->next;
        }
        return res;
    }
};
