package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/8 12:43
 */
public class Solution2 {

  public boolean isPalindrome(ListNode head) {
    ListNode slow = head, fast = head, prev = null;
    while (fast != null && fast.next != null) {
      fast = fast.next.next;
      ListNode next = slow.next;
      slow.next = prev;
      prev = slow;
      slow = next;
    }

    fast = fast == null ? slow : slow.next;
    slow = prev;
    for (; fast != null && slow != null; fast = fast.next, slow = slow.next) {
      if (fast.val != slow.val) return false;
    }
    return true;
  }
}
