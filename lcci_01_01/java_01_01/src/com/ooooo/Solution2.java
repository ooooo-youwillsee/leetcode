package com.ooooo;

public class Solution2 {

    public boolean isUnique(String astr) {
        int sum = 0;
        for (int i = 0; i < astr.length(); i++) {
            int move_bit = astr.charAt(i) - 'a';
            if ((sum & (1 << move_bit)) != 0) return false;
            sum |= (1 << move_bit);
        }
        return true;
    }


    public static void main(String[] args) {
        Solution1 solution = new Solution1();
        System.out.println(solution.isUnique("abc"));
        System.out.println(solution.isUnique("leetcode"));
    }
}
