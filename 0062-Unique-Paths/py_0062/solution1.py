# -*- coding: utf-8 -*-
# @Time    : 2020/12/9 09:02
# @Author  : ooooo


from typing import *

'''
dp[i][j] = dp[i][j-1] + dp[i-1][j]
'''


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0 for j in range(n)] for i in range(m)]
        for i in range(m):
            dp[i][0] = 1
        for i in range(n):
            dp[0][i] = 1
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
        return dp[m - 1][n - 1]
