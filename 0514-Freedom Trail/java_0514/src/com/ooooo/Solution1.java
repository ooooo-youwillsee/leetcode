package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/11/21 11:32
 *
 * timeout
 */
public class Solution1 {
	
	String ring;
	String key;
	int min = Integer.MAX_VALUE;
	
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
		dfs(0, 0, 0);
		return min;
	}
	
	private void dfs(int x, int i, int step) {
		if (i >= key.length()) {
			min = Math.min(min, step);
			return;
		}
		for (int y = 0, sz = ring.length(); y < sz; y++) {
			if (ring.charAt(y) == key.charAt(i)) {
				dfs(y, i + 1, step + calcDist(x, y, sz) + 1);
			}
		}
	}
}
