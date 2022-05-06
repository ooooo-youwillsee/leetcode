package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/5 15:45
 * double pointer
 */
public class Solution2 {

  public int kthToLast(ListNode head, int k) {
    ListNode first = head, second = head;
    for (int i = 0; i < k; i++) {
      first = first.next;
    }
    while (first != null) {
      first = first.next;
      second = second.next;
    }
    return second.val;
  }
}
