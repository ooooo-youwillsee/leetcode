package com.ooooo;

import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * 暴力
 */
class Solution1 {
	
	private Set<Integer> nums;
	private String ans;
	private int k;
	private int n;
	private int count = 0;
	
	
	private boolean dfs(StringBuilder sb) {
		if (nums.isEmpty()) {
			count++;
			if (count == k) {
				ans = sb.toString();
				return true;
			}
			return false;
		}
		for (int i = 1; i <= n; i++) {
			if (!nums.contains(i)) continue;
			sb.append(i);
			nums.remove(i);
			if (dfs(sb)) return true;
			nums.add(i);
			sb.deleteCharAt(sb.length() - 1);
		}
		return false;
	}
	
	public String getPermutation(int n, int k) {
		this.n = n;
		this.k = k;
		nums = IntStream.range(1, n + 1).boxed().collect(Collectors.toSet());
		dfs(new StringBuilder());
		return ans;
	}
	
	private static void test(int n, int k) {
		Solution1 solution = new Solution1();
		String permutation = solution.getPermutation(n, k);
		System.out.println(permutation);
	}
	
	public static void main(String[] args) {
		test(3, 3); // 213
		test(4, 9); // 2314
	}
}