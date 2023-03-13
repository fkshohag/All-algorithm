#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/merge-k-sorted-lists/description/
 */

/**
 * @brief 
 * Time complexity : O(n)
 * Space complexity: O(nlogn)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0);
        ListNode *point = head;
        // Space complexity O(n)
        vector <int> nodes;

        for(ListNode* l : lists) {
            while(l) {
                nodes.push_back(l->val);
                l = l->next;
            }
        }

        // O(nlogn)
        sort(nodes.begin(), nodes.end());
        for (int node : nodes) {
            point->next = new ListNode(node);
            point = point->next;
        }
        return head->next;
    }
};


/**
 * @brief 
 * Time complexity : O(nlogk) k is the number of linkedList
 * Space complexity: O(n)
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0);
        ListNode *point = head;
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > pq(cmp);
        for (ListNode* l : lists) {
            if (l) {
                pq.push(l);
            }
        }
        while (!pq.empty()) {
            ListNode* topNode = pq.top(); pq.pop();
            point->next = topNode;
            point = point->next;
            if (topNode->next) {
                pq.push(topNode->next);
            }
        }
        return head->next;
    }
};