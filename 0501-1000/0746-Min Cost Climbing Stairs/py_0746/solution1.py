# -*- coding: utf-8 -*-
# @Time    : 2020/12/21 10:48
# @Author  : ooooo

from typing import *


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0 for x in range(n + 1)]
        for i in range(2, n + 1):
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
        return dp[n]


