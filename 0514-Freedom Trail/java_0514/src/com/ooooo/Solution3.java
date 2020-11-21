package com.ooooo;

import java.util.Arrays;

/**
 * @author leizhijie
 * @since 2020/11/21 11:32
 * <p>
 * dfs + memo
 */
public class Solution3 {
	
	String ring;
	String key;
	int[][] memo;
	
	int calcDist(int x, int y, int m) {
		if (x < y) {
			return Math.min(y - x, x + m - y);
		} else {
			return Math.min(x - y, m - x + y);
		}
	}
	
	public int findRotateSteps(String ring, String key) {
		this.ring = ring;
		this.key = key;
		this.memo = new int[ring.length() + 1][key.length() + 1];
		for (int[] ints : memo) {
			Arrays.fill(ints, -1);
		}
		return dfs(0, 0);
	}
	
	private int dfs(int x, int i) {
		if (memo[x][i] != -1) return memo[x][i];
		int min_step = Integer.MAX_VALUE;
		if (i >= key.length()) return 0;
		
		for (int y = 0, sz = ring.length(); y < sz; y++) {
			if (ring.charAt(y) == key.charAt(i)) {
				min_step = Math.min(min_step, dfs(y, i + 1) + calcDist(x, y, sz) + 1);
			}
		}
		return memo[x][i] = min_step;
	}
}
