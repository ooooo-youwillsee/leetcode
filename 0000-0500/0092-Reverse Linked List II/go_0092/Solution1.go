package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	if m == n {
		return head
	}
	dummyHead := &ListNode{-1, head}
	var prev, cur *ListNode
	cur = dummyHead
	cnt := 1
	for cnt < m {
		cur = cur.Next
		cnt++
	}

	pre, mNode := cur, cur.Next
	for cnt <= n+1 {
		cnt++
		next := cur.Next
		cur.Next = prev
		prev = cur
		cur = next
	}

	mNode.Next = cur
	pre.Next = prev

	return dummyHead.Next
}

func main() {

}
