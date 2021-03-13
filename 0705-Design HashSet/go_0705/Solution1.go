/**
* @Author: ooooo
* @Date: 2021/3/13 21:20
 */

package go_0705

type MyHashSet struct {
	data []bool
}

/** Initialize your data structure here. */
func Constructor() MyHashSet {
	return MyHashSet{data: make([]bool, 1e6+1)}
}

func (this *MyHashSet) Add(key int) {
	this.data[key] = true
}

func (this *MyHashSet) Remove(key int) {
	this.data[key] = false
}

/** Returns true if this set contains the specified element */
func (this *MyHashSet) Contains(key int) bool {
	return this.data[key]
}
