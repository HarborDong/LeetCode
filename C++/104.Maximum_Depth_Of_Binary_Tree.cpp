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
    
    int maxDepth(TreeNode* root) {
        int length = 0, leftLen = 0, rightLen = 0;
        if(root) {
            leftLen = maxDepth(root->left);
            rightLen = maxDepth(root->right);
            length = 1 + (leftLen > rightLen ? leftLen : rightLen);
        }
        return length;
    }
};
