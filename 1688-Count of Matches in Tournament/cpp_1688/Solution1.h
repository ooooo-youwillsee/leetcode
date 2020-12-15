/**
 * @author ooooo
 * @date 2020/12/15 20:21 
 */

#ifndef CPP_1688__SOLUTION1_H_
#define CPP_1688__SOLUTION1_H_

#include <iostream>
using namespace std;

class Solution {
 public:
	int numberOfMatches(int n) {
		if (n == 1) return 0;
		return n / 2 + numberOfMatches((n + 1) / 2);
	}
};

#endif //CPP_1688__SOLUTION1_H_
