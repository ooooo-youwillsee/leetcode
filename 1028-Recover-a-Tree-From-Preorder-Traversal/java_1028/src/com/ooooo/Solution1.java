package com.ooooo;

class Solution1 {


  private TreeNode dfs(StringBuilder sb, int level) {
    if (sb.length() == 0) return null;
    int start = 0;
    for (; start < sb.length(); start++) {
      if (Character.isDigit(sb.charAt(start))) break;
    }
    int end = start + 1;
    for (; end < sb.length(); end++) {
      if ('-' == sb.charAt(end)) break;
    }
    if (start != level) return null;
    TreeNode node = new TreeNode(Integer.parseInt(sb.substring(start, end)));
    sb.delete(0, end);
    node.left = dfs(sb, level + 1);
    node.right = dfs(sb, level + 1);
    return node;
  }

  public TreeNode recoverFromPreorder(String S) {
    return dfs(new StringBuilder(S), 0);
  }

  private static void test(String s) {
    Solution1 solution = new Solution1();
    TreeNode node = solution.recoverFromPreorder(s);
    System.out.println(node);
  }

  public static void main(String[] args) {
    test("1-2--3--4-5--6--7");
    test("1-2--3---4-5--6---7");
    test("1-401--349---90--88");
  }

}