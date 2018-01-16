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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        deque<TreeNode *> layer;
        vector<int> layerVal;
        int i = 0;
        if(root) {
            layer.push_back(root);
            layerVal.push_back(root->val);
            ret.push_back(layerVal);
            while(ret[i].size()) {
                vector<int> temp;
                for(int j = 0; j < ret[i].size(); j++) {
                    TreeNode *top = layer.front();
                    layer.pop_front();
                    if(top->left) {
                        temp.push_back(top->left->val);
                        layer.push_back(top->left);
                    } 
                    if(top->right) {
                        temp.push_back(top->right->val);
                        layer.push_back(top->right);
                    }
                }
                ret.push_back(temp);
                i++;
            }
            ret.pop_back();
        }
        return ret;
    }
};
