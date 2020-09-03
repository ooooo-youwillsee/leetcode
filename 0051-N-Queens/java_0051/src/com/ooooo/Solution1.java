package com.ooooo;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

class Solution1 {
	
	Set<Integer> cols = new HashSet<>(), pies = new HashSet<>(), nas = new HashSet<>();
	int n = 0;
	
	List<List<String>> ans = new ArrayList<>();
	
	public void dfs(int i, List<StringBuilder> queens) {
		if (i == n) {
			ans.add(queens.stream().map(StringBuilder::toString).collect(Collectors.toList()));
			return;
		}
		for (int j = 0; j < n; j++) {
			if (cols.contains(j) || pies.contains(i + j) || nas.contains(j - i)) continue;
			cols.add(j);
			pies.add(i + j);
			nas.add(j - i);
			queens.get(i).setCharAt(j, 'Q');
			dfs(i + 1, queens);
			queens.get(i).setCharAt(j, '.');
			cols.remove(j);
			pies.remove(i + j);
			nas.remove(j - i);
		}
	}
	
	public List<List<String>> solveNQueens(int n) {
		this.n = n;
		List<StringBuilder> queens = new ArrayList<>(n);
		for (int i = 0; i < n; i++) {
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < n; j++) {
				sb.append(".");
			}
			queens.add(sb);
		}
		dfs(0, queens);
		return ans;
	}
	
	private static void test(int n) {
		Solution1 solution = new Solution1();
		List<List<String>> nQueens = solution.solveNQueens(n);
		for (List<String> queens : nQueens) {
			for (String s : queens) {
				System.out.println(s);
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		test(4);
	}
}