package main

import (
	"fmt"
)

type NumArray struct {
	tree []int
	n    int
	nums []int
}

func (this *NumArray) buildTree(root, l, r int) {
	if l >= r {
		this.tree[root] = this.nums[l]
		return
	}
	mid := l + (r-l)/2
	this.buildTree(leftChild(root), l, mid)
	this.buildTree(rightChild(root), mid+1, r)
	this.tree[root] = merge(this.tree[leftChild(root)], this.tree[rightChild(root)])
}

func merge(x, y int) int {
	return x + y
}

func leftChild(i int) int {
	return 2*i + 1
}
func rightChild(i int) int {
	return 2*i + 2
}

func Constructor(nums []int) NumArray {
	n := len(nums)
	if n == 0 {
		return NumArray{
			tree: nil,
			n:    0,
			nums: nil,
		}
	}
	o := NumArray{
		tree: make([]int, 4*n),
		n:    n,
		nums: nums,
	}
	o.buildTree(0, 0, n-1)
	return o
}

func (this *NumArray) query(ql, qr int) int {
	return this.queryInner(0, 0, this.n-1, ql, qr)
}

func (this *NumArray) queryInner(root, l, r, ql, qr int) int {
	if l == ql && r == qr {
		return this.tree[root]
	}
	mid := l + (r-l)/2
	if mid < ql {
		return this.queryInner(rightChild(root), mid+1, r, ql, qr)
	}
	if qr <= mid {
		return this.queryInner(leftChild(root), l, mid, ql, qr)
	}
	return merge(this.queryInner(leftChild(root), l, mid, ql, mid), this.queryInner(rightChild(root), mid+1, r, mid+1, qr))
}

func (this *NumArray) SumRange(i int, j int) int {
	if this.n == 0 {
		return 0
	}
	return this.query(i, j)
}

func main() {
	numArray := Constructor([]int{-2, 0, 3, -5, 2, -1})
	fmt.Println(numArray.SumRange(0, 2))

}
