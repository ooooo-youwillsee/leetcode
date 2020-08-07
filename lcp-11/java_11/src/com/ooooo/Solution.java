package com.ooooo;

import java.util.Arrays;
import java.util.stream.Collectors;

class Solution {
  
  public int expectNumber(int[] scores) {
    return Arrays.stream(scores).boxed().collect(Collectors.toSet()).size();
  }
  
}