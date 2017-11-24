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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l1_node = l1, *l1_node_prev = NULL, *l2_node = l2, *l2_node_prev = NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        
        while(l1_node && l2_node) {
            if(l1_node->val < l2_node->val) {
                l1_node_prev = l1_node;
                l1_node = l1_node->next;
            } else {
                l2_node_prev = l2_node;
                l2_node = l2_node->next;
                if(l1_node_prev) {
                    l1_node_prev->next = l2_node_prev;
                    l2_node_prev->next = l1_node;
                    l1_node_prev = l2_node_prev;
                } else {
                    l2_node_prev->next = l1_node;
                    l1_node_prev = l2_node_prev;
                    l1 = l2_node_prev;
                }
            }
        }
        if(l2_node) {
            l1_node_prev->next = l2_node;
        }
        return l1;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *l1 = NULL, *l2 = NULL;
        if(lists.size() == 0) return NULL;
        while(lists.size() > 1) {
            vector<ListNode *> temp;
            while(lists.size()/2) {
                l1 = lists.back(); lists.pop_back();
                l2 = lists.back(); lists.pop_back();
                l1 = mergeTwoLists(l1, l2);
                temp.push_back(l1);
            }
            lists.insert(lists.end(), temp.begin(), temp.end());
        }
        return lists.front() ;       
    }
};
