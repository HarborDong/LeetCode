# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        cur = head; pre = None
        while cur:
            cur.next, pre, cur = pre, cur, cur.next
        
        return pre
