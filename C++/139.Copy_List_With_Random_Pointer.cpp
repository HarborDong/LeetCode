/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> record;
        unordered_map<RandomListNode *, RandomListNode *> :: iterator iter = record.end();
        RandomListNode *node = NULL, *pre = NULL, *headCopy = NULL;
        if(head == NULL) return node;
        while(head) {
            if((iter = record.find(head)) == record.end()) {
                node = new RandomListNode(head->label);
                record[head] = node;
            } else {
                node = iter->second;
            }
            if(pre) 
                pre->next = node;
            else
                headCopy = node;
            if(head->random != NULL && node != NULL) {
                if((iter = record.find(head->random)) == record.end()) {
                    node->random = new RandomListNode(head->random->label);
                    record[head->random] = node->random ;
                } else {
                    node->random = iter->second;
                }
            }
            pre = node;
            head = head->next;
        }
        return headCopy;        
    }
};
