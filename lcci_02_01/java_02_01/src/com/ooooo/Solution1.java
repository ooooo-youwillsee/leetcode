package com.ooooo;

import java.util.HashSet;
import java.util.Set;

/**
 * @author leizhijie
 * @since 2020/5/3 15:45
 */
public class Solution1 {

  public ListNode removeDuplicateNodes(ListNode head) {
    Set<Integer> set = new HashSet<>();
    ListNode dummyHead = new ListNode(-1), cur = dummyHead;
    while (head != null) {
      if (!set.contains(head.val)) {
        cur.next = head;
        cur = cur.next;
        set.add(head.val);
      }
      head = head.next;
    }
    cur.next = null;
    return dummyHead.next;
  }


  private static void test(int[] nums) {
    Solution1 solution = new Solution1();
    ListNode head = new ListNode(nums);
    head = solution.removeDuplicateNodes(head);
    for (; head != null; head = head.next) System.out.print(head.val + " -> ");
    System.out.println();
  }

  public static void main(String[] args) {
    test(new int[]{17, 23, 15, 30, 21, 5, 20, 14, 5, 9, 22, 6,
        22, 20, 14, 12, 4, 21, 27, 5, 4, 21, 27, 0, 14, 21, 17,
        27, 6, 12, 28, 17, 29, 8, 17, 13, 7, 26, 7, 31, 27, 8, 31, 19, 5, 23, 9,
        0, 22, 0, 26, 30, 14, 10, 6, 8, 16, 24, 15, 21, 2, 3, 5, 15});
    test(new int[]{1, 2, 3, 3, 2, 1});
    test(null);
  }
}
