package com.ooooo;

public class ListNode {
  
  int val;
  ListNode next;
  
  ListNode() {}
  
  ListNode(int val) { this.val = val; }
  
  ListNode(int val, ListNode next) {
    this.val = val;
    this.next = next;
  }
  
  public ListNode(int[] nums) {
    if (nums.length == 0) return;
    this.val = nums[0];
    this.next = null;
    ListNode cur = this;
    for (int i = 1; i < nums.length; i++) {
      cur.next = new ListNode(nums[i]);
      cur = cur.next;
    }
  }
}