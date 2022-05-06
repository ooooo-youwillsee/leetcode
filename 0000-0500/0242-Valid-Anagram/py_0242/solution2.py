# -*- coding: utf-8 -*-
# @Time    : 2020/11/22 13:05
# @Author  : ooooo

from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)