/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * transform function the set of left child of root(x) is the set of root(y < x)
 * transform function the set of right child of root(x) is the set of root(z > x)
 */
class Solution {
public:
    vector<TreeNode *> generateTreesHelper(int left, int right) {
        vector<TreeNode *> ret, leftChild, rightChild;
        TreeNode *root = NULL; 
        
        if(right < left) {
            ret.push_back(root);    
            return ret;
        }
        for(int i = left; i <= right; i++) {
            leftChild =  generateTreesHelper(left, i - 1);
            rightChild = generateTreesHelper(i + 1, right);
            for(int j = 0; j < leftChild.size(); j++){
                for(int k = 0; k < rightChild.size(); k++){
                    root = new TreeNode(i);
                    root->left = leftChild[j];
                    root->right = rightChild[k];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(n > 0)
            ret = generateTreesHelper(1, n);
        return ret;
    }
};
