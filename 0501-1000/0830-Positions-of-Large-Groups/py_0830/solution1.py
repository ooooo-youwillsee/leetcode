# -*- coding: utf-8 -*-
# @Time    : 2021/1/5 11:13
# @Author  : ooooo

from typing import *


class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        prev = 0
        ans = []
        for i in range(len(s) + 1):
            if i == len(s) or s[i] != s[prev]:
                if i - prev >= 3:
                    ans.append([prev, i - 1])
                prev = i
        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.largeGroupPositions("abbxxxxzzy")) # [[3,6]]
    print(s.largeGroupPositions("abbxxxxzzyyy")) # [[3,6]]
    print(s.largeGroupPositions("abc")) # []
