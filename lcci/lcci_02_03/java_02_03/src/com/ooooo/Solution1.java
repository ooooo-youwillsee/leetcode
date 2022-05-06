package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/6 09:59
 */
public class Solution1 {

  public void deleteNode(ListNode node) {
    if (node == null || node.next == null) {
      node = null;
      return;
    }
    ListNode next = node.next;
    node.val = next.val;
    node.next = next.next;
    next.next = null;
  }
}
