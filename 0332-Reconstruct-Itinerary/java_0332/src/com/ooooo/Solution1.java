package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution1 {
  
  private final Map<String, List<Item>> g = new HashMap<>();
  private int max_count = 0;
  private List<String> ans = new ArrayList<>();
  
  private static class Item {
    
    public String s;
    public boolean visited;
    
    public Item(String s, boolean visited) {
      this.s = s;
      this.visited = visited;
    }
  }
  
  private boolean dfs(String start, List<String> tmp, int count) {
    tmp.add(start);
    List<Item> targets = g.getOrDefault(start, new ArrayList<>());
    for (Item target : targets) {
      if (target.visited) continue;
      target.visited = true;
      if (dfs(target.s, tmp, count + 1)) return true;
      target.visited = false;
    }
    if (count == max_count) {
      ans = new ArrayList<>(tmp);
      return true;
    }
    tmp.remove(tmp.size() - 1);
    return false;
  }
  
  public List<String> findItinerary(List<List<String>> tickets) {
    for (List<String> ticket : tickets) {
      List<Item> targets = g.computeIfAbsent(ticket.get(0),
          k -> new ArrayList<>());
      targets.add(new Item(ticket.get(1), false));
    }
    g.values().forEach(v -> v.sort((x, y) -> x.s.compareTo(y.s)));
    max_count = tickets.size();
    dfs("JFK", new ArrayList<>(), 0);
    return ans;
  }
  
  
  private static void test(List<List<String>> tickets) {
    Solution1 solution = new Solution1();
    List<String> itinerary = solution.findItinerary(tickets);
    for (String s : itinerary) {
      System.out.print(s + " ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    //List<List<String>> tickets1 = new ArrayList<>();
    //tickets1.add(new ArrayList<>(Arrays.asList("JFK", "SFO")));
    //tickets1.add(new ArrayList<>(Arrays.asList("JFK", "ATL")));
    //tickets1.add(new ArrayList<>(Arrays.asList("ATL", "JFK")));
    //tickets1.add(new ArrayList<>(Arrays.asList("ATL", "SFO")));
    //tickets1.add(new ArrayList<>(Arrays.asList("SFO", "ATL")));
    //test(tickets1);
    //
    //List<List<String>> tickets2 = new ArrayList<>();
    //tickets2.add(new ArrayList<>(Arrays.asList("JFK", "KUL")));
    //tickets2.add(new ArrayList<>(Arrays.asList("JFK", "NRT")));
    //tickets2.add(new ArrayList<>(Arrays.asList("NRT", "JFK")));
    //test(tickets2);
    
    List<List<String>> tickets3 = new ArrayList<>();
    tickets3.add(new ArrayList<>(Arrays.asList("EZE", "AXA")));
    tickets3.add(new ArrayList<>(Arrays.asList("TIA", "ANU")));
    tickets3.add(new ArrayList<>(Arrays.asList("ANU", "JFK")));
    tickets3.add(new ArrayList<>(Arrays.asList("JFK", "ANU")));
    tickets3.add(new ArrayList<>(Arrays.asList("ANU", "EZE")));
    tickets3.add(new ArrayList<>(Arrays.asList("TIA", "ANU")));
    tickets3.add(new ArrayList<>(Arrays.asList("AXA", "TIA")));
    tickets3.add(new ArrayList<>(Arrays.asList("TIA", "JFK")));
    tickets3.add(new ArrayList<>(Arrays.asList("ANU", "TIA")));
    tickets3.add(new ArrayList<>(Arrays.asList("JFK", "TIA")));
    test(tickets3);
    
  }
}