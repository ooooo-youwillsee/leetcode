package com.ooooo;

class Solution1 {
  
  public TreeNode sortedListToBST(ListNode head) {
    if (head == null) return null;
    if (head.next == null) return new TreeNode(head.val);
    ListNode lower = head, faster = head, prev = null;
    while (faster != null && faster.next != null) {
      faster = faster.next.next;
      prev = lower;
      lower = lower.next;
    }
    prev.next = null;
    
    TreeNode root = new TreeNode(lower.val);
    root.left = sortedListToBST(head);
    root.right = sortedListToBST(lower.next);
    return root;
  }
  
  private static void test(ListNode head) {
    Solution1 solution = new Solution1();
    TreeNode node = solution.sortedListToBST(head);
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new ListNode(new int[]{-10, -3, 0, 5}));
    test(new ListNode(new int[]{-10, -3, 0, 5, 9}));
  }
}