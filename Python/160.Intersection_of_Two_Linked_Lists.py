class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """

        if not isinstance(headA, ListNode) or \
           not isinstance(headB, ListNode):
            return None
        
        curA = headA; curB = headB
        while curA is not curB:
            if curA == None: 
                curA = headB
            else:
                curA = curA.next
            if curB == None:
                curB = headA
            else:
                curB = curB.next
        
        return curA
    """
    1. algorithm: two pointers
       ptrA traverses list A, ptrB traverses list B, if ptrA reache the end of List A, redirects to the head of list B. the same idea occur to ptrB.
    2. langauge:
       "curA = headB if curA == None else curA.next" is better than "if curA == None: curA = headB else: curA = curA.next"
       more python style, less C/C++ style
    """
