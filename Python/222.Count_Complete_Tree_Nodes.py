# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: TreeNode) -> (bool, int):
        if root == None: return (True, 0)
        
        left_high = 0; next_node = root
        while next_node != None:
            left_high += 1; next_node = next_node.left
            
        right_high = 0; next_node = root
        while next_node != None:
            right_high += 1; next_node = next_node.right 

        if right_high == left_high:
            return (True, right_high)
        else:
            return (False, right_high)
        
    def countNodes(self, root: TreeNode) -> int:
        complete, high = self.isCompleteTree(root)
        
        if complete:
            return 2 ** high - 1
        else:
            return self.countNodes(root.left) + self.countNodes(root.right) + 1
