package com.ooooo;

import java.util.HashMap;
import java.util.Map;

public class Solution1 {

    public boolean canPermutePalindrome(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        boolean even = s.length() % 2 == 0, singleChar = false;
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (even && entry.getValue() % 2 == 1) return false;
            if (entry.getValue() % 2 == 1) {
                if (singleChar) return false;
                singleChar = true;
            }
        }
        return true;
    }

    private static void test(String s) {
        Solution1 solution = new Solution1();
        System.out.println(solution.canPermutePalindrome(s));
    }

    public static void main(String[] args) {
        test("tactcoa");
        test("tactcoab");
    }
}
