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
    int isBalancedHelper(TreeNode* root) {
        int leftLen = 0, rightLen = 0;
        if(root) {
            leftLen = isBalancedHelper(root->left);
            if(leftLen == -1) return -1;
            rightLen = isBalancedHelper(root->right);
            if(rightLen == -1) return -1;

            if(abs(leftLen - rightLen) < 2)
                return 1 + max(leftLen, rightLen);
            else
                return -1;             
        }
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        if(isBalancedHelper(root) >= 0) {
            return true;
        } else {
            return false;
        }
    }
};
