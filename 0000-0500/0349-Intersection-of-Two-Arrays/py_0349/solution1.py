# -*- coding: utf-8 -*-
# @Time    : 2020/11/2 17:51
# @Author  : ooooo


from typing import *

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return set(nums1) & set(nums2)

