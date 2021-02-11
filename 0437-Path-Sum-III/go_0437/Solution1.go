package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var ans = 0

func dfs(root *TreeNode, sum int, selected bool) {
	if root == nil {
		return
	}
	if sum == root.Val {
		ans++
	}
	if !selected {
		dfs(root.Left, sum, false)
		dfs(root.Right, sum, false)
	}
	dfs(root.Left, sum-root.Val, true)
	dfs(root.Right, sum-root.Val, true)
}

func pathSum(root *TreeNode, sum int) int {
	ans = 0
	dfs(root, sum, false)
	return ans
}

func main() {
	root := &TreeNode{
		10,
		&TreeNode{
			5,
			nil,
			nil,
		},
		&TreeNode{
			-3,
			nil,
			nil,
		},
	}
	fmt.Println(pathSum(root, -3))
}
