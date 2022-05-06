package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/6/16 19:34
 */
public class Solution2 {
  
  static class Codec {
    
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
      String res = "";
      if (root == null) {
        res = "null" + ",";
      } else {
        res += root.val + ",";
        res += serialize(root.left);
        res += serialize(root.right);
      }
      return res;
    }
    
    public TreeNode helpeDserialize(List<String> values) {
      String value = values.get(0);
      values.remove(0);
      if ("null".equals(value)) return null;
      TreeNode node = new TreeNode(Integer.parseInt(value));
      node.left = helpeDserialize(values);
      node.right = helpeDserialize(values);
      return node;
    }
    
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
      if ("null".equals(data)) return null;
      List<String> values = new ArrayList<>(Arrays.asList(data.substring(0, data.length() - 1).split(",")));
      return helpeDserialize(values);
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
