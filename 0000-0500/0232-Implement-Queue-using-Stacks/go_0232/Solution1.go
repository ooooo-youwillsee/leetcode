package main

type MyQueue struct {
	s1, s2 []int
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	this.s1 = append(this.s1, x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	ans := this.Peek()
	this.s2 = this.s2[:len(this.s2)-1]
	return ans
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	if len(this.s2) > 0 {
		ans := this.s2[len(this.s2)-1]
		return ans
	}
	for len(this.s1) > 0 {
		this.s2 = append(this.s2, this.s1[len(this.s1)-1])
		this.s1 = this.s1[:len(this.s1)-1]
	}
	return this.Peek()
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return len(this.s1) == 0 && len(this.s2) == 0
}

func main() {

}
