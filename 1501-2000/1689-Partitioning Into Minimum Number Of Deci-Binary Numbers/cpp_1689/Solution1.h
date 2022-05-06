/**
 * @author ooooo
 * @date 2020/12/20 12:59 
 */

#ifndef CPP_1689__SOLUTION1_H_
#define CPP_1689__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int minPartitions(string n) {
		int ans = 0;
		for (int i = 0; i < n.size(); ++i) {
			ans = max(ans, n[i] - '0');
		}
		return ans;
	}
};

#endif //CPP_1689__SOLUTION1_H_
