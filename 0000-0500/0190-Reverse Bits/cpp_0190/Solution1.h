/**
 * @author ooooo
 * @date 2021/3/29 16:35 
 */

#ifndef CPP_0190__SOLUTION1_H_
#define CPP_0190__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t x = 0;
		for (int i = 0; i < 32; i++) {
			if (n & (1 << i)) {
				x |= (1 << (31 - i));
			}
		}
		return x;
	}
};

#endif //CPP_0190__SOLUTION1_H_
