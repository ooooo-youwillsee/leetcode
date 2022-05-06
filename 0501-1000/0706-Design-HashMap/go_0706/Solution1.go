/**
* @Author: ooooo
* @Date: 2021/3/14 08:53
 */

package go_0706

type MyHashMap struct {
	data []int
}

/** Initialize your data structure here. */
func Constructor() MyHashMap {
	data := make([]int, 1e6+1)
	for i := range data {
		data[i] = -1
	}
	return MyHashMap{data}
}

/** value will always be non-negative. */
func (this *MyHashMap) Put(key int, value int) {
	this.data[key] = value
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
func (this *MyHashMap) Get(key int) int {
	return this.data[key]
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
func (this *MyHashMap) Remove(key int) {
	this.data[key] = -1
}
