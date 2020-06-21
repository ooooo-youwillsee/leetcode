package com.ooooo;

class Solution1 {
  
  private ListNode reverse(ListNode node, int k) {
    ListNode cur = node, prev = null;
    int count = 0;
    while (cur != null && count < k) {
      ListNode next = cur.next;
      cur.next = prev;
      prev = cur;
      cur = next;
      count++;
    }
    return prev;
  }
  
  public ListNode reverseKGroup(ListNode head, int k) {
    int count = 0;
    ListNode cur = head, prevHead = head, a = new ListNode(-1), b = a;
    while (cur != null) {
      count++;
      if (count == k) {
        count = 0;
        ListNode next = cur.next;
        a.next = reverse(prevHead, k);
        a = prevHead;
        prevHead.next = next;
        prevHead = next;
        cur = next;
      } else {
        cur = cur.next;
      }
    }
    return b.next == null ? head : b.next;
  }
  
  private static void test(int[] nums, int k) {
    Solution1 solution = new Solution1();
    ListNode node = solution.reverseKGroup(new ListNode(nums), k);
    while (node != null) {
      System.out.print(node.val + "->");
      node = node.next;
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new int[]{1, 2, 3, 4, 5}, 2);
    test(new int[]{1, 2, 3, 4, 5}, 3);
  }
}