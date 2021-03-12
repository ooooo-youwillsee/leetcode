# -*- coding: utf-8 -*-
# @Time    : 2021/3/12 13:18
# @Author  : ooooo

class Node:

    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class Solution:

    def dfs(self, preorder: str):
        if self.i >= len(preorder) or not self.flag:
            return None
        if preorder[self.i] == '#':
            self.i += 2
            return Node(-1)
        num = 0
        while self.i < len(preorder) and preorder[self.i] != ',':
            num = num * 10 + ord(preorder[self.i]) - ord('0')
            self.i += 1
        self.i += 1
        root = Node(num)
        root.left = self.dfs(preorder)
        root.right = self.dfs(preorder)
        if not root.left or not root.right:
            self.flag = False
        return root

    def isValidSerialization(self, preorder: str) -> bool:
        self.i = 0
        self.flag = True
        self.dfs(preorder)
        return self.i >= len(preorder) and self.flag
