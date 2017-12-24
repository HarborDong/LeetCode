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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 1;
        ListNode *tail = head;
        ListNode *next = head;
        if(!head) return head;
        
        while(tail->next) {
            size++;
            tail = tail->next;
        }
        
        k %= size;
         
        if (k) {
            tail->next = head;
            k = size - k;

            while(k) {
                tail = tail->next;
                k--;
            }
            head = tail->next;
            tail->next = NULL;
        }
        return head;
    }
};
