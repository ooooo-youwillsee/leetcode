/**
 * @author ooooo
 * @date 2021/4/10 09:56 
 */

#ifndef CPP_0263__SOLUTION1_H_
#define CPP_0263__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool isUgly(int n) {
		if (n == 1) return true;
		while (n > 1) {
			if (n % 2 == 0) {
				n /= 2;
			} else if (n % 3 == 0) {
				n /= 3;
			} else if (n % 5 == 0) {
				n /= 5;
			} else {
				return false;
			}
		}
		return n == 1;
	}
};

#endif //CPP_0263__SOLUTION1_H_
