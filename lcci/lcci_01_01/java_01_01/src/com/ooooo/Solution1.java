package com.ooooo;

import java.util.HashMap;
import java.util.Map;

public class Solution1 {

    public boolean isUnique(String astr) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < astr.length(); i++) {
            int count = map.getOrDefault(astr.charAt(i), 0);
            if (count >= 1) return false;
            map.put(astr.charAt(i), count + 1);
        }
        return true;
    }


    public static void main(String[] args) {
        Solution1 solution = new Solution1();
        System.out.println(solution.isUnique("abc"));
        System.out.println(solution.isUnique("leetcode"));
    }
}
