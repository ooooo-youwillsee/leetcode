# -*- coding: utf-8 -*-
# @Time    : 2020/10/20 16:40
# @Author  : ooooo

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    @staticmethod
    def new_node(nums):
        cur = this = ListNode(nums[0])
        for i in range(1, len(nums)):
            cur.next = ListNode(nums[i])
            cur = cur.next
        return this


class Solution:

    def reverseList(self, head: ListNode):
        cur, prev = head, None
        while cur:
            next_node = cur.next
            cur.next = prev
            prev = cur
            cur = next_node
        return prev

    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head is None or head.next is None:
            return
        slow, fast, prev_slow = head, head, None
        while fast and fast.next:
            prev_slow = slow
            slow, fast = slow.next, fast.next.next
        left, right = head, slow
        if fast:
            right, slow.next = slow.next, None
        else:
            prev_slow.next = None
        right = self.reverseList(right)
        while right:
            left_next, right_next = left.next, right.next
            left.next, right.next = right, left_next
            left, right = left_next, right_next

        # print
        # cur = head
        # while cur:
        #     print(cur.val, end=" ")
        #     cur = cur.next
        # print()


if __name__ == '__main__':
    s = Solution()
    s.reorderList(ListNode.new_node([1, 2, 3, 4]))
    s.reorderList(ListNode.new_node([1, 2, 3, 4, 5]))
