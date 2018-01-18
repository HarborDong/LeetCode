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
    TreeNode* build(vector<int>::iterator preStart, vector<int>::iterator preEnd,
                   vector<int>::iterator inStart, vector<int>::iterator inEnd,
                   unordered_map<int, vector<int>::iterator> &data) {
        TreeNode *root = NULL;
        vector<int>::iterator pos;
        if(preEnd > preStart) {
            root = new TreeNode(*preStart);
            pos = data[*preStart];
            root->left = build(preStart + 1, preEnd -(inEnd - pos - 1), 
                               inStart, pos, data);
            root->right = build(preStart + (pos- inStart + 1), preEnd, pos + 1, inEnd, data);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = NULL;
        unordered_map<int, vector<int>::iterator> data;
        for(int i = 0; i < inorder.size(); i++) {
            data[inorder[i]] = inorder.begin() + i;
        }
        root  = build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end(), data);
        return root;
    }
};
