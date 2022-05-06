# -*- coding: utf-8 -*-
# @Time    : 2020/10/27 08:50
# @Author  : ooooo

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import *


class Solution:

    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None: return []
        self.nums = []
        stack = [root]
        while len(stack):
            node = stack.pop()
            self.nums.append(node.val)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        return self.nums
