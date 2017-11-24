/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nth = head, *first = head, *nth_prev = NULL;
        int i = 0;
        while(first) {
            i++;
            if (i > n) {
                nth_prev = nth;
                nth = nth->next;
            }
            first = first->next;
        }

        if(nth) {
            if(nth_prev != 0) {
                nth_prev->next = nth->next;
                nth->next = NULL;
            } else {
                head = nth->next;
            }
        }
        delete nth;
        return head;        
    }
};
