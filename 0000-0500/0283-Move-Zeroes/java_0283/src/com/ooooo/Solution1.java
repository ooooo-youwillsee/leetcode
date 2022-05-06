package com.ooooo;

/**
 * @author leizhijie
 * @since 2020/11/19 09:57
 */
public class Solution1 {
	
	public void moveZeroes(int[] nums) {
		int i = 0, j = 0, n = nums.length;
		while (j < n) {
			if (nums[j] != 0) {
				swap(nums, i, j);
				i++;
			}
			j++;
		}
	}
	
	private void swap(int[] nums, int i, int j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	
	public static void main(String[] args) {
		Solution1 solution = new Solution1();
		int[] nums = new int[]{0, 1, 0, 5, 1, 3, 4, 0, 3, 12};
		solution.moveZeroes(nums);
		for (int num : nums) {
			System.out.print(num + " ");
		}
	}
}
