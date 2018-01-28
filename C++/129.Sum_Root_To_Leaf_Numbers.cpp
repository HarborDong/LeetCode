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
    void sumNumbersHelper(TreeNode* root, int &sum, int &number) {
        if(root){
            number = number * 10 + root->val;
            if(!root->left && !root->right) {
                sum += number;
            }
            sumNumbersHelper(root->left, sum, number);
            sumNumbersHelper(root->right, sum, number);
            number = (number- root->val) / 10;
        }
        return;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0, number = 0;
        sumNumbersHelper(root, sum, number);
        return sum;
    }
};
