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
    void reorderList(ListNode* head) {
        int length = 0, i = 0;
        ListNode *node = head, *half = head;
        ListNode *pre = NULL, *cur = NULL, *next = NULL;
        if(head == NULL) return;
        while(node) {
            length++; node = node->next;
        }
        length = length / 2 + length % 2;
        while(i < length) {
            i++; pre = half; half = half->next;
        }
        pre->next = NULL; pre = half; 
        if(half) {
            cur = half->next; half->next = NULL;
        } else {
            return;
        }
        while(cur) {
            next = cur->next; cur->next = pre; pre = cur; cur = next;
        }
        half = pre; node = head;
        while(half) {
            next = half->next; half->next = node->next; node->next = half;
            node = half->next; half = next; 
        }
        return;
    }
};
