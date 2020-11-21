package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/11/21 11:54
 */
public class Solution2 {
	
	int calcDist(int x, int y, int m) {
		if (x < y) {
			return Math.min(y - x, x + m - y);
		} else {
			return Math.min(x - y, m - x + y);
		}
	}
	
	public int findRotateSteps(String ring, String key) {
		int m = ring.length(), n = key.length();
		int ans = Integer.MAX_VALUE;
		int[][] dp = new int[n][m];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = Integer.MAX_VALUE;
			}
		}
		
		for (int y = 0; y < m; y++) {
			if (ring.charAt(y) == key.charAt(0)) {
				dp[0][y] = calcDist(0, y, m) + 1;
			}
		}
		
		for (int i = 1; i < n; i++) {
			for (int x = 0; x < m; x++) {
				if (dp[i - 1][x] != Integer.MAX_VALUE) {
					// dp[i - 1][x] 不为 Integer.MAX_VALUE，表示上一个字符的当前位置,到达过这里
					for (int y = 0; y < m; y++) {
						if (ring.charAt(y) == key.charAt(i)) {
							dp[i][y] = Math.min(dp[i][y], dp[i - 1][x] + calcDist(x, y, m) + 1);
							//System.out.println(String.format("dp[%d][%d] = %d", i, y, dp[i][y]));
						}
					}
				}
			}
		}
		for (int i = 0; i < m; i++) {
			ans = Math.min(ans, dp[n - 1][i]);
		}
		return ans;
	}
	
}
