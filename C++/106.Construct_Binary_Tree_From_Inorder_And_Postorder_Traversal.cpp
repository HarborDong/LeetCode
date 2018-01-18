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
    TreeNode* build(vector<int>::iterator inStart, vector<int>::iterator inEnd,
                   vector<int>::iterator postStart, vector<int>::iterator postEnd,
                   unordered_map<int, vector<int>::iterator> &data) {
        TreeNode *root = NULL;
        vector<int>::iterator pos;
        if(postEnd > postStart) {
            root = new TreeNode(*(postEnd - 1));
            pos = data[*(postEnd - 1)];
            root->left = build(inStart, pos, postStart, postEnd - (inEnd - pos), data);
            root->right = build(pos + 1, inEnd, postStart + (pos- inStart), postEnd - 1, data);          
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = NULL;
        unordered_map<int, vector<int>::iterator> data;
        for(int i = 0; i < inorder.size(); i++) {
            data[inorder[i]] = inorder.begin() + i;
        }
        root  = build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end(), data);
        return root;        
    }
};
