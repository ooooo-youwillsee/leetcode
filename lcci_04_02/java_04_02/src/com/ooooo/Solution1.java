package com.ooooo;

class Solution1 {


    private TreeNode help(int[] nums, int l, int r) {
        if (l > r) return null;
        if (l == r) return new TreeNode(nums[l]);
        int mid = l + (r - l) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = help(nums, l, mid - 1);
        node.right = help(nums, mid + 1, r);
        return node;
    }

    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums == null || nums.length == 0) return null;
        return help(nums, 0, nums.length - 1);
    }
}