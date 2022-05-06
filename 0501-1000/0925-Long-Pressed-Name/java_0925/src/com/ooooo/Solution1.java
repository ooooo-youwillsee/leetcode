package com.ooooo;

import java.util.ArrayList;
import java.util.List;
import javafx.util.Pair;

/**
 * @author leizhijie
 * @since 2020/10/21 08:57
 */
public class Solution1 {
	
	
	private List<Pair<Character, Integer>> help(String s) {
		List<Pair<Character, Integer>> list = new ArrayList<>(s.length());
		int i = 0, count = 1;
		while (i < s.length()) {
			if (i < s.length() - 1 && s.charAt(i) == s.charAt(i + 1)) {
				count++;
			} else {
				list.add(new Pair<>(s.charAt(i), count));
				count = 1;
			}
			i++;
		}
		return list;
	}
	
	public boolean isLongPressedName(String name, String typed) {
		List<Pair<Character, Integer>> name_list = help(name), typed_list = help(typed);
		if (name_list.size() != typed_list.size()) return false;
		for (int i = 0; i < name_list.size(); i++) {
			Pair<Character, Integer> name_group = name_list.get(i), typed_group = typed_list.get(i);
			if (!name_group.getKey().equals(typed_group.getKey()) || name_group.getValue().compareTo(typed_group.getValue()) > 0) return false;
		}
		return true;
	}
	
	public static void main(String[] args) {
		Solution1 solution = new Solution1();
		boolean longPressedName = solution.isLongPressedName("kikcxmvzi", "kiikcxxmmvvzz");
		System.out.println(longPressedName);
	}
}
