# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        """
        the attribution of LCA: q.val <= LCA.val <= q.val
        """
        ancestor = root
        
        while ancestor:
            if ancestor.val > p.val and ancestor.val > q.val:
                ancestor = ancestor.left
            elif ancestor.val < q.val and ancestor.val < p.val:
                ancestor = ancestor.right
            else:
                break
            
        return ancestor
