# -*- coding: utf-8 -*-
# @Time    : 2020/10/27 08:47
# @Author  : ooooo


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import *


class Solution:

    def dfs(self, root: TreeNode):
        if root is None: return
        self.nums.append(root.val)
        self.dfs(root.left)
        self.dfs(root.right)

    def preorderTraversal(self, root: TreeNode) -> List[int]:
        self.nums = []
        self.dfs(root)
        return self.nums
