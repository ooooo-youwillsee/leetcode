# -*- coding: utf-8 -*-
# @Time    : 2020/10/18 12:48
# @Author  : ooooo


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy_head = ListNode()
        dummy_head.next, low, fast = head, dummy_head, dummy_head
        while n > 0:
            fast, n = fast.next, n - 1
        while fast.next is not None:
            fast, low = fast.next, low.next
        low.next = low.next.next
        return dummy_head.next
