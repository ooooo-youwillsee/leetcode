package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var ans = 0

func dfs(root *TreeNode, sum int, prevSum []int) {
	if root == nil {
		return
	}
	if root.Val == sum {
		ans++
	}
	for i := range prevSum {
		prevSum[i] += root.Val
		if prevSum[i] == sum {
			ans++
		}
	}
	prevSum = append(prevSum, root.Val)
	leftPreSum, rightPreSum := make([]int, len(prevSum)), make([]int, len(prevSum))
	copy(leftPreSum, prevSum)
	copy(rightPreSum, prevSum)
	dfs(root.Left, sum, leftPreSum)
	dfs(root.Right, sum, rightPreSum)
}

func pathSum(root *TreeNode, sum int) int {
	ans = 0
	dfs(root, sum, make([]int, 0))
	return ans
}

func main() {

}
