package com.ooooo;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/11/21 10:46
 * 直接排序
 */
public class Solution1 {
	
	public ListNode sortList(ListNode head) {
		List<ListNode> list = new ArrayList<>();
		ListNode cur = head;
		while (cur != null) {
			ListNode next = cur.next;
			cur.next = null;
			list.add(cur);
			cur = next;
		}
		list.sort(Comparator.comparingInt(n -> n.val));
		ListNode dummyHead = new ListNode(-1);
		cur = dummyHead;
		for (ListNode node : list) {
			cur.next = node;
			cur = cur.next;
		}
		return dummyHead.next;
	}
}
