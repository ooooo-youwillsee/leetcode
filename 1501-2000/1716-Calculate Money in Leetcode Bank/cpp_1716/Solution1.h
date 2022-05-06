/**
 * @author ooooo
 * @date 2021/1/20 12:14 
 */

#ifndef CPP_1716__SOLUTION1_H_
#define CPP_1716__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int totalMoney(int n) {
		int prev = 0, count = 1;
		int ans = 0;
		while (n) {
			ans += count + prev;
			count++;
			if (count == 8) {
				count = 1;
				prev++;
			}
			n--;
		}
		return ans;
	}
};

#endif //CPP_1716__SOLUTION1_H_
