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
    bool isValidBSTHelper(TreeNode* root, TreeNode *left, TreeNode *right) {
        if(left && root) {
            if(left->val >= root->val) {
                return false;
            }
        }
        if(right && root) {
            if(right->val <= root->val) {
                return false;
            }
        }
        if(root) {
            if(!isValidBSTHelper(root->left, left, root))
                return false;
            if(!isValidBSTHelper(root->right, root, right))
                return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, NULL, NULL);
    }
};
