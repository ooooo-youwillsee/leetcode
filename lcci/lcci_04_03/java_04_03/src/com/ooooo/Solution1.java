package com.ooooo;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution1 {

  public ListNode[] listOfDepth(TreeNode tree) {
    if (tree == null) { return new ListNode[0]; }
    Queue<TreeNode> q = new LinkedList<>();
    List<List<Integer>> ans = new ArrayList<>();
    q.add(tree);
    while (!q.isEmpty()) {
      List<Integer> rows = new ArrayList<>();
      for (int i = 0, len = q.size(); i < len; i++) {
        TreeNode node = q.poll();
        rows.add(node.val);
        if (node.left != null) { q.add(node.left); }
        if (node.right != null) { q.add(node.right); }
      }
      ans.add(rows);
    }

    ListNode[] listNodes = new ListNode[ans.size()];
    for (int i = 0; i < ans.size(); i++) {
      ListNode dummyHead = new ListNode(-1), cur = dummyHead;
      for (Integer num : ans.get(i)) {
        cur.next = new ListNode(num);
        cur = cur.next;
      }
      listNodes[i] = dummyHead.next;
    }
    return listNodes;
  }
}