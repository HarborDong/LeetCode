# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        cur = head; pre = None
        
        while cur:
            if cur.val == val:
                if pre:
                    pre.next = cur.next
                    cur.next = None
                    del cur; cur = pre.next
                else:
                    head = cur.next
                    cur.next = None
                    del cur; cur = head
            else:
                pre, cur = cur, cur.next
        
        return head

