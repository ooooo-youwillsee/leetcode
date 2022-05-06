# -*- coding: utf-8 -*-
# @Time    : 2020/10/7 00:03
# @Author  : ooooo

from typing import *


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count_0, count_1, count_2 = 0, 0, 0
        for x in nums:
            if 0 == x:
                count_0 += 1
            elif 1 == x:
                count_1 += 1
            elif 2 == x:
                count_2 += 1
        i = 0
        for x in range(count_0):
            nums[i] = 0
            i += 1
        for x in range(count_1):
            nums[i] = 1
            i += 1
        for x in range(count_2):
            nums[i] = 2
            i += 1
