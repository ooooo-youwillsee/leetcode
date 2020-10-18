# -*- coding: utf-8 -*-
# @Time    : 2020/10/19 06:52
# @Author  : ooooo


from typing import *


class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        stack1, stack2 = [], []
        for x in S:
            if x == '#':
                if len(stack1) != 0:
                    stack1.pop()
            else:
                stack1.append(x)
        for x in T:
            if x == '#':
                if len(stack2) != 0:
                    stack2.pop()
            else:
                stack2.append(x)
        return stack1 == stack2
