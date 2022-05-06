package main

import (
	"fmt"
	"strconv"
)

/*
2 / -2 = -1 + 0
-1 / -2 = 1 + 1
1 / -2 = 0 + 1

*/
func baseNeg2(N int) string {
	if N == 0 {
		return "0"
	}
	var sb []string
	const BASE = -2
	for N != 0 {
		a := N / BASE
		b := N % BASE
		if b < 0 {
			b += -BASE
			a += 1
		}
		sb = append(sb, strconv.Itoa(b))
		N = a
	}
	ans := ""
	for i := len(sb) - 1; i >= 0; i-- {
		ans += sb[i]
	}
	return ans
}

func main() {
	fmt.Println(-1 / -2) // 0
	fmt.Println(-1 % -2) // -1
	fmt.Println(baseNeg2(3))
	fmt.Println(baseNeg2(2))

}
