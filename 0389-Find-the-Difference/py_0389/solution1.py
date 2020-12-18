# -*- coding: utf-8 -*-
# @Time    : 2020/12/18 21:23
# @Author  : ooooo

from typing import *


class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        i = 0
        for c in s:
            i ^= ord(c)
        for c in t:
            i ^= ord(c)
        return str(chr(i))
