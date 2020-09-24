# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root:
            return
        if not root.left and not root.right:
            return [str(root.val)]

        left = self.binaryTreePaths(root.left)
        right = self.binaryTreePaths(root.right)
        left = [str(root.val) + '->' + seg for seg in left] if left else []
        right = [str(root.val) + '->' + seg for seg in right] if right else []
        
        return left + right
