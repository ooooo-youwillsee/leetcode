/**
 * @author ooooo
 * @date 2021/4/4 08:30 
 */

#ifndef CPP_1806__SOLUTION1_H_
#define CPP_1806__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:

	int reinitializePermutation(int n) {
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			int cur = i, next = i;
			do {
				if (next % 2 == 0) {
					next = next / 2;
				} else {
					next = n / 2 + (next - 1) / 2;
				}
				cnt++;
			} while (next != cur);
			ans = max(ans, cnt);
		}
		return ans;
	}
};

#endif //CPP_1806__SOLUTION1_H_
