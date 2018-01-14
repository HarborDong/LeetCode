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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        TreeNode *top = NULL;
        vector<int> ret;
        int flag = 1;
        if(!root)
            return ret;
        else
            stk.push(root);
        while(stk.size()) {
            top = stk.top();
            if(top->left && flag) {
                stk.push(top->left);
                flag = 1;
            } else {
                ret.push_back(top->val);
                stk.pop();
                if(top->right) {
                    stk.push(top->right);
                    flag = 1;
                }
                else
                    flag = 0;
            }
        }
        return ret;
    }
};
