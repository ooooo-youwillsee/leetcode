# -*- coding: utf-8 -*-
# @Time    : 2020/10/13 17:09
# @Author  : ooooo


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


from typing import *


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummyHead = ListNode(-1)
        prev = dummyHead
        dummyHead.next = head
        while prev.next and prev.next.next:
            one, two = prev.next, prev.next.next
            print("one: %d, two: %d" %(one.val, two.val))
            one.next = two.next
            prev.next, two.next, = two, one,
            prev = one
        return dummyHead.next
