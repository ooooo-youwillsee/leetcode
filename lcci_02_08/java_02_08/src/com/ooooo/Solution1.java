package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/6 14:09
 */
public class Solution1 {

  public ListNode detectCycle(ListNode head) {
    ListNode low = head, fast = head;
    while (fast != null && fast.next != null) {
      low = low.next;
      fast = fast.next.next;
      if (low == fast) break;
    }
    if (fast == null || fast.next == null) return null;
    low = head;
    while (low != fast) {
      low = low.next;
      fast = fast.next;
    }
    return low;
  }
}
