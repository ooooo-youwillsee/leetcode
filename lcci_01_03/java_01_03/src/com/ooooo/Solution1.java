package com.ooooo;

public class Solution1 {

    public String replaceSpaces(String S, int length) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; i++) {
            char c = S.charAt(i);
            if (c == ' ') sb.append("%20");
            else sb.append(c);
        }
        return sb.toString();
    }

    private static void test(String s, int count){
        Solution1 solution = new Solution1();
        System.out.println(solution.replaceSpaces(s, count));
    }

    public static void main(String[] args) {
        test("Mr John Smith    ", 13);
        test("               ", 5);
    }
}
