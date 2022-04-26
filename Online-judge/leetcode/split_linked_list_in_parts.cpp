/**
* @author Md.Shohag <shohag.fks@gmail.com>
* Problem : https://leetcode.com/problems/split-linked-list-in-parts/
*/


# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = 0;

        ListNode *curr = head;
        while(curr != NULL) {
        	curr = curr->next;
        	N++; 
        }

        int width = N / k;
        int rem = N % k;
        curr = head;
        vector <ListNode*> list;

        for (int slot = 0; slot < k; slot++) {
        	ListNode *slotNode = curr;

        	for (int j = 0; j < width + (slot < rem ? 1 : 0) - 1; j++) {
        		if (curr != NULL) {
        			curr = curr->next;
        		}
        	}

        	if (curr != NULL) {
        		ListNode *perSlotNode = curr;
        		curr = curr->next;
        		perSlotNode->next = NULL;
        	}

        	list.push_back(slotNode);
        }
        return list; 
    }
};

int main () {
	Solution s;
	ListNode *newNode2 = new ListNode(3);
	ListNode *newNode1 = new ListNode(2, newNode2);
	ListNode *newNode = new ListNode(1, newNode1);
	s.splitListToParts(newNode, 5);
}