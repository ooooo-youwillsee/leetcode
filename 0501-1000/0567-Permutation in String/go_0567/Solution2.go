package main

import (
	"fmt"
)

func checkInclusion(s1 string, s2 string) bool {
	m := make([]int, 26)
	for _, v := range s1 {
		m[v-'a']++
	}
	l, r, count := 0, 0, 0
	for r < len(s2) {
		if m[s2[r]-'a'] == 0 {
			l = r - count
			if l == r {
				r++
				continue
			}
			// 只回收当前一个字符
			if count > 0 {
				m[s2[l]-'a']++
				count--
			}
		} else {
			m[s2[r]-'a']--
			count++
			if count == len(s1) {
				return true
			}
			r++
		}
	}
	return false
}

func main() {
	fmt.Println(checkInclusion("ab", "eidbaooo"))
	fmt.Println(checkInclusion("ab", "eidboaoo"))
	fmt.Println(checkInclusion("adc", "dcda"))
}
