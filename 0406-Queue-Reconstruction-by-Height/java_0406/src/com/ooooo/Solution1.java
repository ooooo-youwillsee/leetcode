package com.ooooo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/11/16 09:33
 */
public class Solution1 {
	
	public int[][] reconstructQueue(int[][] people) {
		Arrays.sort(people, (o1, o2) -> {
			int h1 = o1[0], h2 = o2[0];
			int k1 = o1[1], k2 = o2[1];
			if (h1 == h2) {
				return k1 - k2;
			} else {
				return h2 - h1;
			}
		});
		
		List<int[]> list = new ArrayList<>();
		for (int[] person : people) {
			int h = person[0], k = person[1];
			//System.out.println(String.format("h: %d, k: %d", h, k));
			list.add(k, person);
		}
		return list.toArray(new int[0][0]);
	}
	
	
}
