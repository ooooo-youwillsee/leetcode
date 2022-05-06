package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/6 10:26
 *
 * 重用节点
 */
public class Solution1 {

  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    boolean plusOne = false;
    ListNode dummyHead = new ListNode(-1), prev = dummyHead;
    while (l1 != null || l2 != null) {
      int val1 = 0, val2 = 0;
      prev.next = null;
      if (l1 != null) {
        val1 = l1.val;
        prev.next = l1;
        l1 = l1.next;
      }

      if (l2 != null) {
        val2 = l2.val;
        prev.next = l2;
        l2 = l2.next;
      }

      int val = val1 + val2 + (plusOne ? 1 : 0);
      plusOne = val >= 10;
      prev.next.val = plusOne ? val - 10 : val;
      prev = prev.next;
    }

    if (plusOne) prev.next = new ListNode(1);

    return dummyHead.next;
  }

}
