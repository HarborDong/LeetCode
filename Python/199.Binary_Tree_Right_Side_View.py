# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: 'TreeNode') -> 'List[int]':
        cur = 0; end = 1;
        cur_level_end = 0; nxt_level_end = 0
        ret = []; stack = []
        if not root: return []
        stack.append(root)
        while cur != end:
            if stack[cur].left:
                stack.append(stack[cur].left)
                end += 1
            if stack[cur].right:
                stack.append(stack[cur].right)
                end += 1
            if cur == cur_level_end:
                ret.append(stack[cur].val)
                cur_level_end = end -1
            cur += 1
        return ret
