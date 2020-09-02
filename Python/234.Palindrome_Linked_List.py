# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:       
    def isPalindrome(self, head: ListNode) -> bool:
        """
        reverse half of list
        """
        slow = fast = head
        reverse = None

        while fast and fast.next:
            reverse, reverse.next, slow, fast = slow, reverse, slow.next, fast.next.next

        if fast != None:
            slow = slow.next
        
        while slow:
            # print(slow, reverse)
            if slow.val == reverse.val:
                slow, reverse = slow.next, reverse.next
            else:
                return False

        return True
