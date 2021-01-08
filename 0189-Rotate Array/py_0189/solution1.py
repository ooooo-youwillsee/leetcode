# -*- coding: utf-8 -*-
# @Time    : 2021/1/8 14:51
# @Author  : ooooo

from typing import *


class Solution:

    def reverse(self, nums, i, j):
        while i <= j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        self.reverse(nums, 0, n - 1)
        self.reverse(nums, 0, k - 1)
        self.reverse(nums, k, n - 1)


if __name__ == '__main__':
    s = Solution()
    nums1 = [1, 2, 3, 4, 5, 6, 7]
    # [5,6,7,1,2,3,4]
    s.rotate(nums1, 3)
    print(nums1)

    nums2 = [-1, -100, 3, 99]
    # nums2 = [ -100, 3, 99, -1,]
    s.rotate(nums2, 3)
    print(nums2)
