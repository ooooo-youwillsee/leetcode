# -*- coding: utf-8 -*-
# @Time    : 2020/12/1 09:29
# @Author  : ooooo


from typing import *
from bisect import bisect_left, bisect_right


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0 or target > nums[-1] or target < nums[0]:
            return [-1, -1]
        l, r = bisect_left(nums, target), bisect_right(nums, target)
        # print(l, r)
        if nums[l] != target:
            return [-1, -1]
        return [l, r - 1]


if __name__ == '__main__':
    s = Solution()
    print(s.searchRange([5, 7, 7, 8, 9, 10], 8))
    print(s.searchRange([5, 7, 7, 8, 8, 10], 8))
    print(s.searchRange([5, 7, 7, 8, 8, 10], 6))
