package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/10/21 09:19
 */
public class Solution2 {
	
	public boolean isLongPressedName(String name, String typed) {
		if (name.length() > typed.length()) return false;
		int i = 0, j = 0;
		while (i < name.length() && j < typed.length()) {
			if (name.charAt(i) == typed.charAt(j)) {
				i++;
			} else {
				if (j == 0 || typed.charAt(j - 1) != typed.charAt(j)) return false;
			}
			j++;
		}
		while (j < typed.length()) {
			if (typed.charAt(j) != typed.charAt(j - 1)) return false;
			j++;
		}
		return i == name.length();
	}
	
	public static void main(String[] args) {
		Solution2 solution = new Solution2();
		boolean longPressedName1 = solution.isLongPressedName("kikcxmvzi", "kiikcxxmmvvzz");
		boolean longPressedName2 = solution.isLongPressedName("kikcxmvziv", "kiikcxxmmvvzzi");
		boolean longPressedName3 = solution.isLongPressedName("alex", "alexxr");
		System.out.println(longPressedName1);
		System.out.println(longPressedName2);
		System.out.println(longPressedName3);
	}
}
