package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author leizhijie
 * @since 2020/8/6 09:26
 */
public class Solution2 {
  
  private Map<String, Integer> word_indexes = new HashMap<>();
  private Node root = new Node();
  
  private static class Node {
    
    private int index;
    private Map<Character, Node> next;
    
    public Node() {
      this.index = -1;
      this.next = new HashMap<>(26);
    }
  }
  
  
  private void buildTrie(String[] words) {
    for (int i = 0; i < words.length; i++) {
      String word = words[i];
      word_indexes.put(word, i);
      Node curNode = root;
      for (int j = word.length() - 1; j >= 0; j--) {
        curNode = curNode.next.computeIfAbsent(word.charAt(j), k -> new Node());
      }
      curNode.index = i;
    }
  }
  
  private int findWord(String word, int l, int r) {
    Node curNode = root;
    while (l <= r) {
      curNode = curNode.next.get(word.charAt(l));
      if (curNode == null) return -1;
      l++;
    }
    return curNode.index;
  }
  
  private boolean isPalindrome(String s, int i, int j) {
    for (; i < j; i++, j--) {
      if (s.charAt(i) != s.charAt(j)) return false;
    }
    return true;
  }
  
  
  public List<List<Integer>> palindromePairs(String[] words) {
    buildTrie(words);
    List<List<Integer>> ans = new ArrayList<>();
    for (int i = 0; i < words.length; i++) {
      String word = words[i];
      int m = word.length();
      for (int j = 0; j <= m; j++) {
        if (j < m && isPalindrome(word, 0, j)) {
          int right = findWord(word, j + 1, m - 1);
          if (right != -1 && right != i) {
            ans.add(Arrays.asList(right, i));
          }
        }
        if (isPalindrome(word, j, m - 1)) {
          int left = findWord(word, 0, j - 1);
          if (left != -1 && left != i) {
            ans.add(Arrays.asList(i, left));
          }
        }
      }
    }
    return ans;
  }
  
  private static void test(String[] words) {
    Solution2 solution = new Solution2();
    List<List<Integer>> pairs = solution.palindromePairs(words);
    for (List<Integer> pair : pairs) {
      System.out.print(String.format("[%d, %d] ", pair.get(0), pair.get(1)));
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    test(new String[]{
        "abcd", "dcba", "lls", "s", "sssll"
    }); // [0,1],[1,0],[3,2],[2,4]
  }
}
