package com.ooooo;

class Solution1 {

  private void swapValue(ListNode node1, ListNode node2) {
    int tmp = node1.val;
    node1.val = node2.val;
    node2.val = tmp;
  }

  public ListNode partition(ListNode head, int x) {
    ListNode dummyHead = new ListNode(-1), prev = dummyHead;
    dummyHead.next = head;
    while (head != null) {
      if (head.val < x) {
        swapValue(prev.next, head);
        prev = prev.next;
      }
      head = head.next;
    }

    return dummyHead.next;
  }
}