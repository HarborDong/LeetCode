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

    ListNode* quickSortList(ListNode* head, ListNode *end) {
        ListNode *cur = NULL, *next = NULL, *flag = NULL, *pre = NULL;
        ListNode *temp = NULL, *temp1 = NULL;

        if(head && head != end) {
            cur = head->next;
            flag = head; pre = head;
        } else {
            return head;
        }
        
        while(cur && cur != end) {
            next = cur->next;
            if(cur->val < flag->val) {
                pre->next = next;
                cur->next = head;
                head = cur;
                if(!temp) temp = cur;
            } else if (cur->val == flag->val) {
                pre->next = next;
                if(temp) {
                    cur->next = temp->next;
                    temp->next = cur;
                } else {
                    cur->next = head;
                    temp = cur; head = cur;
                }
            }else {
                pre = cur;
            }
            cur = next;
        }

        next = flag->next;
        flag->next = NULL;
        if((temp && temp->next == flag) || !temp)
            head = quickSortList(head, flag);
        else 
            head = quickSortList(head, temp->next);
        next = quickSortList(next, end);
        flag->next = next;

        return head;
    }
    ListNode* sortList(ListNode* head) {
        head = quickSortList(head, NULL);
        return head;
    }
};
