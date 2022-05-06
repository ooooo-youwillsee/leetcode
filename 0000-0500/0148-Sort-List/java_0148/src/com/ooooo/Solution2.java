package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/11/21 10:54
 */
public class Solution2 {
	
	public ListNode sortList(ListNode head) {
		if (head == null || head.next == null) return head;
		ListNode low = head, fast = head, prev_low = null;
		while (fast != null && fast.next != null) {
			prev_low= low;
			low = low.next;
			fast = fast.next.next;
		}
		prev_low.next = null;
		ListNode sortLeft = sortList(head);
		ListNode sortRight = sortList(low);
		ListNode dummyHead = new ListNode(-1), cur = dummyHead;
		while (sortLeft != null && sortRight != null) {
			System.out.println(sortLeft.val + " " + sortRight.val);
			if (sortLeft.val <= sortRight.val) {
				cur.next = sortLeft;
				sortLeft = sortLeft.next;
			} else {
				cur.next = sortRight;
				sortRight = sortRight.next;
			}
			cur = cur.next;
		}
		while (sortLeft != null) {
			cur.next = sortLeft;
			sortLeft = sortLeft.next;
			cur = cur.next;
		}
		while (sortRight != null) {
			cur.next = sortRight;
			sortRight = sortRight.next;
			cur = cur.next;
		}
		return dummyHead.next;
	}
}
