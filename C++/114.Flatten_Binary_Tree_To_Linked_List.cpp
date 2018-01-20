/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * 把root的左子树移到以前右子树的位置，以前的右子树移到之前兄弟左子树的，最右叶节点
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root) {
            TreeNode* cur;
            if(root->left) {
                cur = root->left;
                while(cur->right) {
                    cur = cur->right;
                }
                cur->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
        return;
    }
};
