/**
* @Author: ooooo
* @Date: 2021/2/11 09:43
 */

package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type KthLargest struct {
	sort.IntSlice
	nums []int
}

func (o *KthLargest) Len() int {
	return len(o.nums)
}

func (o *KthLargest) Less(i, j int) bool {
	return o.nums[i] < o.nums[j]
}

func (o *KthLargest) Swap(i, j int) {
	o.nums[i], o.nums[j] = o.nums[j], o.nums[i]
}

func (o *KthLargest) Push(x interface{}) {
	o.nums = append(o.nums, x.(int))
}

func (o *KthLargest) Pop() interface{} {
	sz := len(o.nums)
	x := o.nums[sz-1]
	o.nums = o.nums[:sz-1]
	return x
}

func Constructor(k int, nums []int) KthLargest {
	h := &KthLargest{
		nums: make([]int, 0, k),
	}
	heap.Init(h)
	for _, v := range nums {
		if h.Len() < k {
			heap.Push(h, v)
		} else {
			if minValue := h.nums[0]; minValue < v {
				heap.Pop(h)
				heap.Push(h, v)
			}
		}
	}

	return *h
}

func (this *KthLargest) Add(val int) int {
	if this.Len() < cap(this.nums) {
		heap.Push(this, val)
	} else if minValue := this.nums[0]; minValue < val {
		heap.Pop(this)
		heap.Push(this, val)
	}
	return this.nums[0]
}

func main() {
	k := Constructor(1, []int{})
	// ["KthLargest","add","add","add","add","add"]
	// [[1,[]],[-3],[-2],[-4],[0],[4]]
	fmt.Println(k.Add(-3))
	fmt.Println(k.Add(-2))
	fmt.Println(k.Add(-4))
	fmt.Println(k.Add(0))
	fmt.Println(k.Add(4))
}
