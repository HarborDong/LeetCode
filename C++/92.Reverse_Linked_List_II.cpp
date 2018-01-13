/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 方法1：使用3个指针遍历单链表，逐个链接点进行反转。
 * 方法2：从第2个节点到第N个节点，依次逐节点插入到第1个节点(head节点)之后，最后将第一个节点挪到新表的表尾。
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *mPointer = NULL, *nPointer = NULL, *mPre = NULL;
        ListNode *cur = head, *pre  = NULL, *next = NULL;
        int index = 1;
        for(; index < m - 1; index++;) {
            cur = cur->next;
        }
        mPre = cur;
        mPointer = cur->next;
        pre = cur;
        cur = cur->next;

        if(index == m) {
            mPre = pre;
            mPointer = cur;
            if(mPre) mPre->next = NULL;
            next = cur->next;
            cur->next = NULL;
            pre = cur;
            cur = next;
        }
        while(index < n) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            index++;
        }
        
        if(mPre) {
            mPre->next = pre;
        } else {
            head = pre;
        }
        
        mPointer->next = cur;

        return head;        
    }
};

//method 1
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *mPointer = NULL, *nPointer = NULL, *mPre = NULL;
        ListNode *cur = head, *pre  = NULL, *next = NULL;
        int i = 0, temp = 0;
        while(i <= n) {
            i++;
            if(i < m) {
                pre = cur;
                cur = cur->next;
            }
            if(m == i) {
                mPointer = cur;
                mPre = pre;
            }
            if(m < i && i <= n) {
                cur = mPointer->next;
                if(mPre) {
                    next = mPre->next;
                    mPre->next = cur;
                    mPointer->next = cur->next;
                    cur->next = next;
                } else {
                    next = head;
                    head = mPointer->next;
                    mPointer->next = head->next;
                    head->next = next;
                }
            }

        }

        return head;        
    }
};
