# -*- coding: utf-8 -*-
# @Time    : 2020/12/13 10:26
# @Author  : ooooo

from typing import *


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)
