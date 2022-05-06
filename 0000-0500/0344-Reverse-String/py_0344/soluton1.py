# -*- coding: utf-8 -*-
# @Time    : 2020/10/8 09:47
# @Author  : ooooo

from typing import *


class Solution:
    def reverseString(self, s: List[str]) -> None:
        for i in range(len(s) // 2):
            s[i], s[-i - 1] = s[-i - 1], s[i]
