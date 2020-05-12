package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/3 15:45
 */
public class ListNode {

  int val;
  ListNode next;

  ListNode(int x) { val = x; }

  ListNode(int[] arr) {
    if (arr == null) return;
    this.val = arr[0];
    ListNode cur = this;
    for (int i = 1; i < arr.length; i++) {
      cur.next = new ListNode(arr[i]);
      cur = cur.next;
    }
  }
}
