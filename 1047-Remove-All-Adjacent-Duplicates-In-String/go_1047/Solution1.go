package main

import (
	"fmt"
)

func removeDuplicates(s string) string {
	stack := make([]byte, 0)
	for _, v := range s {
		if len(stack) > 0 && stack[len(stack)-1] == byte(v) {
			stack = stack[:len(stack)-1]
		} else {
			stack = append(stack, byte(v))
		}
	}
	return string(stack)
}

func main() {
	fmt.Println(removeDuplicates("abbaac"))

}
