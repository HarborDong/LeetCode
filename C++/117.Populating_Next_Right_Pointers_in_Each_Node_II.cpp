/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur = root, *pre = NULL, *layHead = root;
        while(layHead) {
            cur = layHead;
            layHead = NULL;
            pre = NULL;
            while(cur) {
                if(cur->left) {
                    if(!layHead) layHead = cur->left;
                    if(pre) pre->next = cur->left;
                    pre = cur->left; 
                } 
                if (cur->right) {
                    if(!layHead) layHead = cur->right;
                    if(pre) pre->next = cur->right;
                    pre = cur->right;
                }
                cur = cur->next;
            }
        }
        return;
    }
};
