package com.ooooo;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

/**
 * timeout
 */
class Solution1 {

  private Map<Integer, List<Integer>> transform(int[] A) {
    Map<Integer, List<Integer>> map = new HashMap<>();
    for (int i = 0; i < A.length; i++) {
      List<Integer> indexes = map.getOrDefault(A[i], new ArrayList<>());
      indexes.add(i);
      map.put(A[i], indexes);
    }
    return map;
  }

  private int compare(int[] A, int i, int[] B, int j) {
    int len = 0;
    while (i < A.length && j < B.length && A[i] == B[j]) {
      i++;
      j++;
      len++;
    }
    return len;
  }

  public int findLength(int[] A, int[] B) {
    int len = 0;
    Map<Integer, List<Integer>> a_map = transform(A);
    Map<Integer, List<Integer>> b_map = transform(B);
    if (a_map.size() > b_map.size()) {
      Map<Integer, List<Integer>> tmp_map = a_map;
      a_map = b_map;
      b_map = tmp_map;
      int[] tmp_arr = A;
      A = B;
      B = tmp_arr;
    }
    for (Entry<Integer, List<Integer>> entry : a_map.entrySet()) {
      int num = entry.getKey();
      List<Integer> indexes = entry.getValue();
      if (!b_map.containsKey(num)) continue;
      for (Integer a_index : indexes) {
        for (Integer b_index : b_map.get(num)) {
          len = Math.max(len, compare(A, a_index, B, b_index));
        }
      }
    }
    return len;
  }

  private static void test(int[] A, int[] B) {
    Solution1 solution = new Solution1();
    int n = solution.findLength(A, B);
    System.out.println(n);
  }

  public static void main(String[] args) {
//    test(new int[]{19, 7, 42, 95, 19, 84, 49, 7, 44, 61, 22, 98, 71, 31, 97, 14, 48, 47, 33, 18, 58,
//            11, 60, 42, 69, 76, 72, 73, 21, 26, 82, 65, 73, 63, 74, 5, 16, 8, 63, 23, 10, 56, 30, 92,
//            34, 36, 62, 37, 15, 78, 49, 48, 3, 55, 78, 9, 29, 77, 40, 83, 51, 81, 12, 97, 46, 38, 97,
//            72, 66, 73, 70, 1, 56, 38, 6, 64, 27, 76, 3, 42, 13, 51, 41, 71, 7, 34, 36, 41, 34, 98, 25,
//            86, 81, 9, 1, 65, 58, 36, 37, 95},
//        new int[]{44, 98, 89, 43, 98, 16, 59, 70, 69, 56, 46, 68, 38, 16, 55, 35, 33, 20, 32, 48,
//            80, 1, 69, 65, 31, 58, 71, 1, 99, 94, 58, 17, 31, 96, 27, 37, 44, 27, 42, 25, 48, 2, 48,
//            86, 94, 90, 30, 41, 47, 56, 55, 51, 4, 94, 75, 79, 63, 7, 64, 25, 57, 12, 0, 28, 20, 80,
//            28, 26, 52, 48, 73, 30, 49, 48, 3, 55, 78, 9, 29, 77, 40, 83, 51, 81, 12, 97, 46, 38,
//            97, 72, 66, 73, 70, 1, 56, 38, 6, 48, 83, 70});
    test(new int[]{1, 2, 3, 2, 1}, new int[]{3, 2, 1, 4, 7}); // 3

  }
}