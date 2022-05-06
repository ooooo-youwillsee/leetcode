# -*- coding: utf-8 -*-
# @Time    : 2021/1/4 09:32
# @Author  : ooooo


from typing import *


class Solution:
    def fib(self, n: int) -> int:
        if n == 0 or n == 1:
            return n
        a, b = 0, 1
        for i in range(n - 1):
            a, b = b, a + b
        return b
