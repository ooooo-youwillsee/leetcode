package com.ooooo;

import java.util.HashSet;
import java.util.Set;

/**
 * @author leizhijie
 * @since 2020/5/8 15:33
 */
public class Solution1 {

  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    if (headA == null || headB == null) return null;
    Set<ListNode> set = new HashSet<>();
    for (; headA != null; headA = headA.next) set.add(headA);
    for (; headB != null; headB = headB.next) {
      if (set.contains(headB)) return headB;
    }
    return null;
  }
}
