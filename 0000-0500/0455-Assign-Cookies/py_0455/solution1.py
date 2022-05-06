# -*- coding: utf-8 -*-
# @Time    : 2020/12/25 09:18
# @Author  : ooooo


from typing import *


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        i, j = 0, 0
        cnt = 0
        while i < len(g):
            assigned = False
            while j < len(s):
                if g[i] <= s[j]:
                    cnt += 1
                    j += 1
                    assigned = True
                    break
                j += 1
            if not assigned:
                break
            i += 1
        return cnt


if __name__ == '__main__':
    s = Solution()
    print(s.findContentChildren([1, 2, 3], s=[1, 1]))
