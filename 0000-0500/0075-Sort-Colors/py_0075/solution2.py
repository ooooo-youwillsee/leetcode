# -*- coding: utf-8 -*-
# @Time    : 2020/10/7 00:07
# @Author  : ooooo

from typing import *


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        l, r, k = 0, len(nums) - 1, 0
        while l <= r:
            if nums[l] == 0:
                nums[l], nums[k] = nums[k], nums[l]
                l += 1
                k += 1
            elif nums[l] == 1:
                l += 1
            elif nums[l] == 2:
                nums[l], nums[r] = nums[r], nums[l]
                r -= 1
