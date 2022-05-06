# -*- coding: utf-8 -*-
# @Time    : 2020/10/16 20:07
# @Author  : ooooo

from typing import *


class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        return sorted([x ** 2 for x in A])
