# -*- coding: utf-8 -*-
# @Time    : 2020/10/3 09:06
# @Author  : ooooo

from typing import *


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i, num in enumerate(nums):
            if target - num in m:
                return [m[target - num], i]
            m[num] = i
        return []
