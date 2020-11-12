# -*- coding: utf-8 -*-
# @Time    : 2020/11/12 12:10
# @Author  : ooooo

from typing import *


class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        even_nums, odd_nums = [], []
        for num in A:
            if num % 2 == 0:
                even_nums.append(num)
            else:
                odd_nums.append(num)
        ans, l, r = [], 0, 0
        for i in range(len(A)):
            if i % 2 == 0:
                ans.append(even_nums[l])
                l += 1
            else:
                ans.append(odd_nums[r])
                r += 1
        return ans
