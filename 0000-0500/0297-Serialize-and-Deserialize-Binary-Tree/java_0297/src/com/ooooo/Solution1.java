package com.ooooo;

import java.util.LinkedList;
import java.util.Queue;

/**
 * @author leizhijie
 * @since 2020/6/16 15:47
 */
public class Solution1 {
  
  static class Codec {
    
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
      if (root == null) return "[null]";
      StringBuilder sb = new StringBuilder("[");
      Queue<TreeNode> q = new LinkedList<>();
      q.add(root);
      while (!q.isEmpty()) {
        StringBuilder tmp = new StringBuilder();
        int count_null = 0, len = q.size();
        for (int i = 0; i < len; i++) {
          TreeNode node = q.poll();
          if (node == null) {
            tmp.append("null,");
            count_null++;
          } else {
            tmp.append(node.val).append(",");
            q.add(node.left);
            q.add(node.right);
          }
        }
        if (count_null == len) break;
        else sb.append(tmp.toString());
      }
      sb.deleteCharAt(sb.length() - 1);
      return sb.append("]").toString();
    }
    
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
      if ("[null]".equals(data)) return null;
      String[] values = data.substring(1, data.length() - 1).split(",");
      TreeNode root = new TreeNode(Integer.parseInt(values[0]));
      Queue<TreeNode> q = new LinkedList<>();
      q.add(root);
      for (int i = 1; i < values.length; i += 2) {
        TreeNode node = q.poll();
        if (!"null".equals(values[i])) {
          node.left = new TreeNode(Integer.parseInt(values[i]));
          q.add(node.left);
        }
        if (i + 1 >= values.length) break;
        if (!"null".equals(values[i + 1])) {
          node.right = new TreeNode(Integer.parseInt(values[i + 1]));
          q.add(node.right);
        }
      }
      return root;
    }
  }
  
  public static void main(String[] args) {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.right.left = new TreeNode(4);
    root.right.right = new TreeNode(5);
    Codec c = new Codec();
    
    String s = c.serialize(root);
    System.out.println(s);
    TreeNode node = c.deserialize(s);
    System.out.println(node);
    
  }
}
