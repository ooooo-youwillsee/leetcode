# -*- coding: utf-8 -*-
# @Time    : 2020/10/23 08:53
# @Author  : ooooo


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        nums, cur = [], head
        while cur:
            nums.append(cur.val)
            cur = cur.next
        for i in range(len(nums) // 2):
            if nums[i] != nums[len(nums) - i - 1]:
                return False
        return True
