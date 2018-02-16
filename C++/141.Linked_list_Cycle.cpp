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
    bool hasCycle(ListNode *head) {
        ListNode *first  = head, *second = head;
        
        while(first && second) {
            first = first->next;
            if(second->next) {
                second = second->next->next;
            } else {
                return false;
            }
            if(second == first) return true;
        }
        return false;
    }
};
