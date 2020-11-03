# -*- coding: utf-8 -*-
# @Time    : 2020/11/3 09:04
# @Author  : ooooo


from typing import *


class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3: return False
        high, low = False, False
        for i in range(1, len(A)):
            if A[i] > A[i - 1]:
                if low: return False
                high = True
            elif A[i] < A[i - 1]:
                if not high: return False
                low = True
            else:
                return False
        return high and low
