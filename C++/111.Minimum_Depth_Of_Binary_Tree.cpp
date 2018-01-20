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
    int minDepth(TreeNode* root) {
        int length = 0, leftLen = 0, rightLen = 0;
        if(root) {
            leftLen = minDepth(root->left);
            rightLen = minDepth(root->right);

            length = min(leftLen, rightLen);
            if(length == 0)
                length = 1 + max(leftLen, rightLen);
            else
                length += 1;
        }
        return length;        
    }
};
