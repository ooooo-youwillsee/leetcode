# -*- coding: utf-8 -*-
# @Time    : 2020/12/27 09:38
# @Author  : ooooo

from typing import *


class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        m1, m2 = {}, {}
        for i in range(len(s)):
            if s[i] in m1:
                if m1[s[i]] != t[i]:
                    return False
            if t[i] in m2:
                if m2[t[i]] != s[i]:
                    return False
            m1[s[i]] = t[i]
            m2[t[i]] = s[i]
        return True
