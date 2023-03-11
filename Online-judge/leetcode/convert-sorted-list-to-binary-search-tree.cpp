#include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 */

/**
 * @brief 
 * Time complexity : O(n)
 * Space complexity: O(n)
 */
 
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
    vector<int> list;
    
    void linkListToList(ListNode* head) {
        while(head) {
            list.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode* listToTreeNode(int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(list[mid]);

        node->left = listToTreeNode(left, mid - 1);
        node->right = listToTreeNode(mid + 1, right);
        return node;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        linkListToList(head);
        return listToTreeNode(0, list.size() - 1);
    }
};