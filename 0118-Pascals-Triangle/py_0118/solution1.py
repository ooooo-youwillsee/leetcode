# -*- coding: utf-8 -*-
# @Time    : 2020/12/6 09:38
# @Author  : ooooo


from typing import *


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0: return []
        ans = [[1]]
        for row in range(2, numRows + 1):
            ans.append([1 for i in range(row)])
            for i in range(1, row - 1):
                ans[-1][i] = ans[-2][i] + ans[-2][i - 1]
        return ans
