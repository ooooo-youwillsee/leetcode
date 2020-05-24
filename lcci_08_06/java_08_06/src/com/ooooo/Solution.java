package com.ooooo;

import java.util.ArrayList;
import java.util.List;

class Solution {

  private void mv(int num, List<Integer> A, List<Integer> B, List<Integer> C) {
    if (num == 0) return;
    mv(num - 1, A, C, B);
    C.add(A.remove(A.size() - 1));
    mv(num - 1, B, A, C);
  }

  public void hanota(List<Integer> A, List<Integer> B, List<Integer> C) {
    mv(A.size(), A, B, C);
  }

  public static void main(String[] args) {
    Solution solution = new Solution();
    List<Integer> A = new ArrayList<Integer>();
    A.add(2);
    A.add(1);
    A.add(0);
    solution.hanota(A, new ArrayList<>(), new ArrayList<>());
  }
}