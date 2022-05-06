# -*- coding: utf-8 -*-
# @Time    : 2020/10/20 16:30
# @Author  : ooooo


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        nodes, cur = [], head
        while cur is not None:
            nodes.append(cur)
            cur = cur.next
            nodes[-1].next = None
        new_nodes, i, j = [], 0, len(nodes) - 1
        while i <= j:
            new_nodes.append(nodes[i])
            if i != j: new_nodes.append(nodes[j])
            i, j = i + 1, j - 1
        prev = ListNode()
        for item in new_nodes:
            prev.next = item
            prev = item
