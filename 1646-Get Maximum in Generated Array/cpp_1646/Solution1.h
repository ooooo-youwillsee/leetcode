/**
 * @author ooooo
 * @date 2021/2/28 13:02 
 */

#ifndef CPP_1646__SOLUTION1_H_
#define CPP_1646__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution {
 public:

	unordered_map<int, int> memo;

	int getGenerated(int n) {
		if (memo.find(n) != memo.end()) return memo[n];
		if (n == 0 || n == 1) return n;
		int ans = n;
		if (n % 2 == 0) {
			ans = getGenerated(n / 2);
		} else {
			ans = getGenerated(n / 2) + getGenerated(n / 2 + 1);
		}
		return memo[n] = ans;
	}
	int getMaximumGenerated(int n) {
		int ans = 0;
		for (int i = 0; i <= n; ++i) {
			ans = max(getGenerated(i), ans);
		}
		return ans;
	}

#endif //CPP_1646__SOLUTION1_H_
