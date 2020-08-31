# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode, k: int):
        if root == None:
            return
        
        self.inorderTraversal(root.left, k)
        if len(self.res) == k: return
        self.res.append(root.val)
        self.inorderTraversal(root.right, k)
        
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        """
        binary tree, root->left < root ->right
        inorder traversal, little middle big
        """
        self.res = []
        self.inorderTraversal(root,k)
        return self.res.pop()
        
        
        
        
        
