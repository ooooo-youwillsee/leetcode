# -*- coding: utf-8 -*-
# @Time    : 2020/10/28 09:03
# @Author  : ooooo

from typing import *


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        m = {}
        for num in arr:
            m[num] += m.get(num, 0) + 1
        return len(set(m.values())) == len(m.values())
