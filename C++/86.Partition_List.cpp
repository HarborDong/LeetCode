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
    ListNode* partition(ListNode* head, int x) {
        ListNode *greaterQ = NULL, *qPre = NULL;
        ListNode *pre = NULL, *cur = head;
        
        while(cur) {
            if(cur->val >= x) {
                if(!pre) {
                    head = cur->next;
                } else {
                    pre->next = cur->next;
                }
                if(!qPre) {
                    greaterQ = cur;
                } else {
                    qPre->next = cur;
                }
                qPre = cur; cur = cur->next; qPre->next = NULL;
            } else {
                pre = cur; cur = cur->next;
            }
        }
    
        if(head) {
            pre->next = greaterQ;
        } else {
            head = greaterQ;
        }
        return head;
    }
};
