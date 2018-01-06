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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head, *pre = NULL, *next = NULL;
        bool skip = false;
        while(cur) {
            skip = false;
            while(cur->next && cur->next->val == cur->val) {
                skip = true;
                cur = cur->next;
            } 
            if(skip == true) {
                if(head->val == cur->val) {
                    head = cur->next;
                }
                if(pre) {
                    pre->next = cur->next;
                }
                next = cur->next;
                cur->next = 0;
                cur = next;
            } else {
                pre = cur;
                cur = cur->next; 
            }
        }
        return head;
    }
};
