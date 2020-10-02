# -*- coding: utf-8 -*-
# @Time    : 2020/10/2 09:23
# @Author  : ooooo


class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return sum([s in J for s in S])
