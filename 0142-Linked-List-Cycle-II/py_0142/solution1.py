# -*- coding: utf-8 -*-
# @Time    : 2020/10/10 11:46
# @Author  : ooooo


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        low, fast = head, head
        while fast and fast.next:
            low, fast = low.next, fast.next.next
            if low == fast:
                break
        if not fast or not fast.next:
            return None
        fast = head
        while low is not fast:
            low, fast = low.next, fast.next
        return low
