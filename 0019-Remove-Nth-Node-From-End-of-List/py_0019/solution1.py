# -*- coding: utf-8 -*-
# @Time    : 2020/10/18 12:39
# @Author  : ooooo


from typing import *


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        cur, sz = head, 0
        while cur is not None:
            cur, sz = cur.next, sz + 1
        dummy_head = ListNode()
        dummy_head.next, cur, sz = head, dummy_head, sz - n
        while sz > 0:
            cur, sz = cur.next, sz - 1
        cur.next = cur.next.next
        return dummy_head.next
