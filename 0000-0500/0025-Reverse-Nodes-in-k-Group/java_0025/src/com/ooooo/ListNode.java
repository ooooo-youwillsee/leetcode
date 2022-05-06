package com.ooooo;

public class ListNode {
  
  int val;
  ListNode next;
  
  ListNode(int x) { val = x; }
  
  ListNode(int[] nums) {
    if (nums == null || nums.length == 0) return;
    this.val = nums[0];
    this.next = null;
    ListNode cur = this;
    for (int i = 1; i < nums.length; i++) {
      cur.next = new ListNode(nums[i]);
      cur = cur.next;
    }
  }
}