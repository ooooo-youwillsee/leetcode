package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/11/21 10:45
 */
public class ListNode {
	
	int val;
	ListNode next;
	
	ListNode() {}
	
	ListNode(int val) { this.val = val; }
	
	ListNode(int val, ListNode next) {
		this.val = val;
		this.next = next;
	}
}
