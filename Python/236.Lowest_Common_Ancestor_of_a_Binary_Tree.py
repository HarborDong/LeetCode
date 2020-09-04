# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == p or root == q or root == None:
            return root
        
        root_r = self.lowestCommonAncestor(root.right, p, q)
        root_l = self.lowestCommonAncestor(root.left, p, q)
        
        if root_r and root_l:
            return root
        else:
            return root_r if root_r else root_l
