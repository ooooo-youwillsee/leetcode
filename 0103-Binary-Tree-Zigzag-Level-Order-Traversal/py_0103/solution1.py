# -*- coding: utf-8 -*-
# @Time    : 2020/12/22 09:40
# @Author  : ooooo

from typing import *
from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        q = deque()
        q.append(root)
        reverse = False
        ans = []
        while len(q):
            sz, levels = len(q), []
            while sz > 0:
                node = q.popleft()
                levels.append(node.val)
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
                sz -= 1
            if reverse:
                levels = list(reversed(levels))
            ans.append(levels)
            reverse = not reverse
        return ans
