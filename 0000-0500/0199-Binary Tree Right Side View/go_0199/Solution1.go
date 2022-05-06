package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rightSideView1(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	q := []*TreeNode{root}
	var ans []int
	for len(q) > 0 {
		for sz := len(q); sz > 0; sz-- {
			node := q[0]
			q = q[1:]
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}

			if sz == 1 {
				ans = append(ans, node.Val)
			}
		}
	}
	return ans
}

func main() {

}
