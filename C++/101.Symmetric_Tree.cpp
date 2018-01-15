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
    bool isSymmetricHelper(TreeNode *rRoot, TreeNode *lRoot) {
        if(!rRoot && !lRoot)
            return true;
        else if(rRoot && lRoot) {
            if(rRoot->val == lRoot->val)
                return isSymmetricHelper(rRoot->left, lRoot->right) &&
                       isSymmetricHelper(rRoot->right, lRoot->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return isSymmetricHelper(root->left, root->right);
    }
};
