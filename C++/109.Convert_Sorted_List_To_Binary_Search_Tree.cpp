/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
        TreeNode* root = NULL;
        int middle = 0;
        if(end >= start) {
            middle = start + (end - start + 1) / 2;
            root = new TreeNode(nums[middle]);
            root->left = sortedArrayToBSTHelper(nums, start, middle - 1);
            root->right = sortedArrayToBSTHelper(nums, middle + 1, end);
        }
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBSTHelper(nums, 0 , nums.size() - 1);
    }
};
