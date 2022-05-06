# -*- coding: utf-8 -*-
# @Time    : 2020/10/23 08:56
# @Author  : ooooo


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        low, fast, prev = head, head, None
        while fast and fast.next:
            fast = fast.next.next
            cur_node, next_node = low, low.next
            cur_node.next = prev
            prev = cur_node
            low = next_node
        l, r = prev, low
        if fast:
            r = low.next
        while l and r:
            if l.val != r.val:
                return False
            l, r = l.next, r.next
        return True
