package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/5/8 15:36
 */
public class Solution2 {

  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    if (headA == null || headB == null) return null;
    ListNode nodeA = headA, nodeB = headB;
    while (nodeA != null && nodeB != null) {
      nodeA = nodeA.next;
      nodeB = nodeB.next;
    }
    nodeA = nodeA == null ? headB : nodeA;
    nodeB = nodeB == null ? headA : nodeB;
    while (nodeA != null && nodeB != null) {
      nodeA = nodeA.next;
      nodeB = nodeB.next;
    }
    nodeA = nodeA == null ? headB : nodeA;
    nodeB = nodeB == null ? headA : nodeB;
    while (nodeA != null && nodeB != null) {
      if (nodeA == nodeB) return nodeA;
      nodeA = nodeA.next;
      nodeB = nodeB.next;
    }
    return null;
  }

}
