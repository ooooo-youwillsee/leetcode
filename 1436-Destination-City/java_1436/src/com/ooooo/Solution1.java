package com.ooooo;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class Solution1 {
  
  public String destCity(List<List<String>> paths) {
    return dfs(paths.get(0).get(0), paths);
  }
  
  private String dfs(String city, List<List<String>> paths) {
    for (List<String> path : paths) {
      if (path.get(0).equals(city)) {
        return dfs(path.get(1), paths);
      }
    }
    return city;
  }
  
  private static void test(String[][] paths) {
    List<List<String>> p = Arrays.stream(paths)
        .map(path -> Arrays.stream(path).collect(Collectors.toList()))
        .collect(Collectors.toList());
    Solution1 solution = new Solution1();
    String city = solution.destCity(p);
    System.out.println(city);
  }
  
  public static void main(String[] args) {
    test(new String[][]{
        {"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}
    }); // "Sao Paulo"
    
    test(new String[][]{
        {"B", "C"}, {"D", "B"}, {"C", "A"}
    }); // "A"
  }
}