package com.ooooo;

import java.util.ArrayList;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/5/5 15:38
 */
public class Solution1 {

  public int kthToLast(ListNode head, int k) {
    List<Integer> nodes = new ArrayList<>();
    for (; head != null; head = head.next) nodes.add(head.val);
    return nodes.get(nodes.size() - k);
  }
}
