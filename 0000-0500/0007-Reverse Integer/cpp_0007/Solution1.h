/**
 * @author ooooo
 * @date 2021/5/3 18:23 
 */

#ifndef CPP_0007__SOLUTION1_H_
#define CPP_0007__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int reverse(int x) {
		int sum = 0;
		while (x) {
			if (sum < INT_MIN / 10 || sum > INT_MAX / 10) {
				return 0;
			}
			sum = sum * 10 + x % 10;
			x = x / 10;
		}

		return sum;
	}
};
#endif //CPP_0007__SOLUTION1_H_
