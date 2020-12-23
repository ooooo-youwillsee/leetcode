# -*- coding: utf-8 -*-
# @Time    : 2020/12/23 08:59
# @Author  : ooooo

class Solution:
    def firstUniqChar(self, s: str) -> int:
        map = {}
        for c in s:
            if c in map:
                map[c] += 1
            else:
                map[c] = 1
        for i in range(len(s)):
            if map[s[i]] == 1:
                return i
        return -1
