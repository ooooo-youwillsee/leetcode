# -*- coding: utf-8 -*-
# @Time    : 2020/10/14 19:36
# @Author  : ooooo

from typing import *


class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        commons = []
        for c in set(A[0]):
            times = len(A[0])
            for x in A:
                times = min(times, x.count(c))
            for i in range(times):
                commons.append(c)
        return commons


if __name__ == '__main__':
    s = Solution()
    ans = s.commonChars(["bella", "label", "roller"])
    print(ans)
