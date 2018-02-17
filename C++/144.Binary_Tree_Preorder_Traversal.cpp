/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> ret;
        int flag = 1;
        TreeNode *node = NULL;
        if(root) {
            ret.push_back(root->val);
            stk.push(root);
        } else {
            return ret;
        }
        
        while(stk.size()) {
            node = stk.top();
            if(flag) {
                if(node->left) {
                    ret.push_back(node->left->val);
                    stk.push(node->left);
                } else {
                    flag = 0;
                }
            } else {
                stk.pop();
                if(node->right) {
                    ret.push_back(node->right->val);
                    stk.push(node->right);
                    flag = 1;
                }
            }
        }
        return ret;
    }
};
