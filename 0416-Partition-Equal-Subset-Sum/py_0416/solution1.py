# -*- coding: utf-8 -*-
# @Time    : 2020/10/11 09:04
# @Author  : ooooo

from typing import *


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False
        total //= 2
        dp = [[False for _ in range(total + 1)] for _ in range(len(nums))]
        dp[0][0] = True
        for i, num in enumerate(nums):
            for j in range(total + 1):
                if j == 0:
                    dp[i + 1][j] = True
                else:
                    if j >= num:
                        dp[i + 1][j] = dp[i][j - num]
                    dp[i + 1][j] = dp[i + 1][j] or dp[i][j]
        return dp[len(nums)][total]


if __name__ == '__main__':
    s = Solution()
    print(s.canPartition([1, 2, 5, ]))
