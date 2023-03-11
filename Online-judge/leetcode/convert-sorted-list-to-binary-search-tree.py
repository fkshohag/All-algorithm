'''
/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 */

/**
 * @brief 
 * Time complexity : O(n)
 * Space complexity: O(logn)
 */
'''

from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def getLinkedListSize(self, head: Optional[ListNode]) -> int:
        size = 0
        ptr = head
        while ptr:
            ptr = ptr.next
            size += 1
        return size

    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        size: int = self.getLinkedListSize(head)

        def listToBST(left, right):
            nonlocal head
            if left > right:
                return None
            mid = left + (right - left) // 2
            leftNode = listToBST(left, mid - 1)

            node = TreeNode(head.val)
            node.left = leftNode
            head = head.next

            node.right = listToBST(mid + 1, right)
            return node
        return listToBST(0, size - 1)

        