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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *pre = NULL, *cur = NULL, *next = NULL;
        ListNode *newHead = NULL, *node = head;
        if(head == NULL) return NULL;
        newHead = head; node = head->next; newHead->next = NULL;
        while(node) {
            pre = NULL; cur = newHead;
            next = node->next; node->next = NULL;
            while(cur) {
                if(cur->val < node->val) {
                    if(cur->next) {
                        pre = cur; cur = cur->next;
                    } else {
                        cur->next = node; break;
                    }
                } else {
                    if(pre) {
                        pre->next = node; node->next = cur; break;
                    } else {
                        node->next = newHead; newHead = node; break;
                    }
                }
            }
            node = next;
        }
        return newHead;
    }
};
