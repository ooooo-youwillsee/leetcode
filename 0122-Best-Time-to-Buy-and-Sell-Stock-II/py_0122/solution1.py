# -*- coding: utf-8 -*-
# @Time    : 2020/11/8 16:21
# @Author  : ooooo

from typing import *


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cur_min = prices[0]
        max_profit = 0
        for i in range(1, len(prices)):
            if prices[i] > cur_min:
                max_profit += prices[i] - cur_min
            cur_min = prices[i]
        return max_profit
