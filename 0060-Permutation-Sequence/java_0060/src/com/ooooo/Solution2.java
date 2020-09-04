package com.ooooo;

import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * @author leizhijie
 * @since 2020/9/5 00:26
 */
public class Solution2 {
	
	Set<Integer> set;
	
	private int compute(int a, int b, int n) {
		int i = a + (b == 0 ? 0 : 1);
		i = i == 0 ? set.size() : i;
		for (int j = 1, count = 0; j <= n; j++) {
			if (!set.contains(j)) continue;
			count++;
			if (count == i) {
				set.remove(j);
				return j;
			}
		}
		return -1;
	}
	
	public String getPermutation(int n, int k) {
		int[] nums = new int[n];
		nums[0] = 1;
		for (int i = 1; i < n; i++) {
			nums[i] = nums[i - 1] * i;
		}
		set = IntStream.range(1, n + 1).boxed().collect(Collectors.toSet());
		
		StringBuilder sb = new StringBuilder();
		int len = n;
		while (sb.length() < len) {
			int a = k / nums[n - 1], b = k % nums[n - 1];
			sb.append(compute(a, b, len));
			n--;
			k = b;
		}
		
		return sb.toString();
	}
	
	private static void test(int n, int k) {
		Solution2 solution = new Solution2();
		String permutation = solution.getPermutation(n, k);
		System.out.println(permutation);
	}
	
	public static void main(String[] args) {
		test(3, 2); // 132
		//test(4, 9); // 2314
		//test(3, 3); // 213
	}
}
