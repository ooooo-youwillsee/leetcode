package com.ooooo;

import java.util.ArrayList;
import java.util.List;

/**
 * @author leizhijie
 * @since 2020/9/4 23:31
 */
public class Solution1 {
	
	private final List<String> paths = new ArrayList<>();
	
	private void dfs(TreeNode root, String path) {
		if (root == null) return;
		if (root.left == null && root.right == null) {
			paths.add(path + root.val);
			return;
		}
		path += root.val + "->";
		dfs(root.left, path);
		dfs(root.right, path);
	}
	
	public List<String> binaryTreePaths(TreeNode root) {
		dfs(root, "");
		return paths;
	}
	
	public static void main(String[] args) {
		TreeNode root = new TreeNode(1);
		root.left = new TreeNode(2);
		root.right = new TreeNode(3);
		root.left.right = new TreeNode(5);
		Solution1 solution = new Solution1();
		List<String> treePaths = solution.binaryTreePaths(root);
		treePaths.forEach(System.out::println);
	}
}
