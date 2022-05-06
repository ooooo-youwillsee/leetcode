# -*- coding: utf-8 -*-
# @Time    : 2021/1/4 14:44
# @Author  : ooooo

from typing import *


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = []
        ans = []
        for i in range(len(nums)):
            if len(q) > 0 and q[0] <= i - k:
                q.pop(0)
            while len(q) > 0 and nums[q[-1]] < nums[i]:
                q.pop()
            q.append(i)
            if i >= k - 1:
                ans.append(nums[q[0]])
        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.maxSlidingWindow([1, 3, 1, 2, 0, 5], 3))  # [3,3,2,5]
    print(s.maxSlidingWindow([1, 3, -1, -3, 5, 3, 6, 7], 3))  # [3,3,5,5,6,7]
    print(s.maxSlidingWindow([1, ], 1))  # [1]
    print(s.maxSlidingWindow([1, -1], 1))  # [1,-1]
    print(s.maxSlidingWindow([9, 11], 2))  # [11]
