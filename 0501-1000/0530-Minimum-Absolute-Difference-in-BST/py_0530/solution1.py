# -*- coding: utf-8 -*-
# @Time    : 2020/10/12 11:09
# @Author  : ooooo

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


from typing import *


class Solution:

    def dfs(self, node: TreeNode):
        if node is None:
            return
        self.dfs(node.left)
        if self.prev is not None:
            self.diff = min(self.diff, node.val - self.prev.val)
        self.prev = node
        self.dfs(node.right)

    def getMinimumDifference(self, root: TreeNode) -> int:
        self.diff = float('inf')
        self.prev = None
        self.dfs(root)
        return self.diff
