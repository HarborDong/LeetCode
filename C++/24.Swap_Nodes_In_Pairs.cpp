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
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev = NULL, *node = head;
        while(node && node->next) {
            if(prev) {
                prev->next = node->next;
                node->next = node->next->next;
                prev->next->next = node;
            } else {
                head = node->next;
                node->next = node->next->next;
                head->next = node;
            }
            prev = node;
            node = node->next;
        }
        return head;
    }
};
