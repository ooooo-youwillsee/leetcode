# -*- coding: utf-8 -*-
# @Time    : 2020/12/1 09:44
# @Author  : ooooo

from typing import *


class Solution:

    def binary_search_right(self, target):
        l, r = 0, len(self.nums) - 1
        while l < r:
            mid = l + (r - l + 1) // 2
            if self.nums[mid] > target:
                r = mid - 1
            else:
                l = mid
        return l if self.nums[l] == target else -1

    def binary_search_left(self, target):
        l, r = 0, len(self.nums) - 1
        while l < r:
            mid = l + (r - l) // 2
            if self.nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l if self.nums[l] == target else -1

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1, -1]
        self.nums = nums
        return [self.binary_search_left(target), self.binary_search_right(target)]


if __name__ == '__main__':
    s = Solution()
    print(s.searchRange([5, 7, 7, 8, 9, 10], 4))
    print(s.searchRange([5, 7, 7, 8, 9, 10], 11))
    print(s.searchRange([5, 7, 7, 8, 9, 10], 8))
    print(s.searchRange([5, 7, 7, 8, 8, 10], 8))
    print(s.searchRange([5, 7, 7, 8, 8, 10], 6))
