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
    /**
     * 假设起点是A, 进入环的点是B,快指针和慢指针相遇在C.
     * 慢指针在C相遇前走过的路程为A->B + B->C
     * 快指针在C相遇前走过的路程为A->B + B->C + C->B + B->C
     * 快指针走过的路程是慢指针的两倍, 所以 2 *（A->B + B->C）
　　　　 * = A->B + B->C + C->B + B->C,故A->B = C->B
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode *first  = head, *second = head;
        int flag = 0;
        while(second && second->next) {
            first = first->next;
            second = second->next->next;

            if(second == first) {
                flag = 1;
                break;
            };
        }
        if(flag) {
            first = head;
            while(first != second) {
                first = first->next;
                second = second->next;
            }
            return first;
        } else {
            return NULL;
        }
    }
};
