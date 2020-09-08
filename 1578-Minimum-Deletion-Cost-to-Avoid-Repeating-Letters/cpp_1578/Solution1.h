/**
 * @author ooooo
 * @date 2020/9/7 16:00 
 */

#ifndef CPP_1578__SOLUTION1_H_
#define CPP_1578__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
 public:
	int minCost(string s, vector<int> &cost) {
		int i = -1, ans = 0;
		s += '$';
		for (int j = 0; j < s.size() - 1; ++j) {
			if (s[j] == s[j + 1]) {
				if (i == -1) i = j;
			} else {
				if (i == -1) continue;
				sort(cost.begin() + i, cost.begin() + j + 1);
				ans += accumulate(cost.begin() + i, cost.begin() + j, 0);
				i = -1;
			}
		}
		return ans;
	}
};

#endif //CPP_1578__SOLUTION1_H_
