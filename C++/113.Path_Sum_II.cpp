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
    void pathSumHelper(TreeNode *root, int sum, vector<int> &element, vector<vector<int>> &ret) {
        if(root) {
            element.push_back(root->val);
            if(sum == root->val && root->right == NULL && root->left == NULL) {
                ret.push_back(element);
            }
            pathSumHelper(root->left, sum - root->val, element, ret);
            pathSumHelper(root->right, sum - root->val, element, ret);
            element.pop_back();
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> element;
        pathSumHelper(root, sum, element, ret);
        return ret;
    }
};
