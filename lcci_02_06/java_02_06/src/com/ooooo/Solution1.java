package com.ooooo;

import java.util.ArrayList;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/5/8 12:36
 */
public class Solution1 {

  public boolean isPalindrome(ListNode head) {
    List<Integer> list = new ArrayList<>();
    for (; head != null; head = head.next) list.add(head.val);
    int n = list.size();
    int l = n / 2 - 1, r = (n & 1) == 0 ? n / 2 : n / 2 + 1;
    while (l >= 0 && r < n) {
      if (!list.get(l).equals(list.get(r))) return false;
      l--;
      r++;
    }
    return true;
  }


}
