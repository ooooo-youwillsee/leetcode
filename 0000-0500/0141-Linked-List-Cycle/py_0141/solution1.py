# -*- coding: utf-8 -*-
# @Time    : 2020/10/9 09:24
# @Author  : ooooo


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        low, fast = head, head
        while fast and fast.next:
            low = low.next
            fast = fast.next.next
            if low == fast:
                return True
        return False
