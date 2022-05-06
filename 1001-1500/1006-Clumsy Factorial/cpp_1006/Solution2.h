/**
 * @author ooooo
 * @date 2021/4/1 18:03 
 */

#ifndef CPP_1006__SOLUTION2_H_
#define CPP_1006__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:

	int clumsy(int N) {
		if (N == 1) {
			return N;
		} else if (N == 2) {
			return N * (N - 1);
		} else if (N == 3) {
			return N * (N - 1) / (N - 2);
		}
		int sum = N * (N - 1) / (N - 2);
		N -= 3;
		while (N >= 4) {
			sum += N - (N - 1) * (N - 2) / (N - 3);
			N -= 4;
		}
		return sum + (N > 0 ? 1 : 0);
	}
};

#endif //CPP_1006__SOLUTION2_H_
