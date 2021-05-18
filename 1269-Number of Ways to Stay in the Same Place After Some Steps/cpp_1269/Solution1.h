/**
 * @author ooooo
 * @date 2021/5/13 21:19 
 */

#ifndef CPP_1269__SOLUTION1_H_
#define CPP_1269__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:

	int mod = 1e9 + 7;
	unordered_map<int, unordered_map<int, long long>> memo;

	long long dfs(int cur, int restStep, int arrLen) {
		if (cur < 0 || cur >= arrLen || restStep < 0) {
			return 0;
		}
		if (memo.find(cur) != memo.end()) {
			if (memo[cur].find(restStep) != memo[cur].end()) {
				return memo[cur][restStep];
			}
		}
		if (cur == 0 && restStep == 0) {
			return memo[cur][restStep] = 1;
		}
		long long sum = 0;
		restStep--;
		sum = (sum + dfs(cur, restStep, arrLen)) % mod;
		sum = (sum + dfs(cur + 1, restStep, arrLen)) % mod;
		sum = (sum + dfs(cur - 1, restStep, arrLen)) % mod;
		return memo[cur][restStep + 1] = sum;
	}
	int numWays(int steps, int arrLen) {
		return dfs(0, steps, arrLen);
	}
};
#endif //CPP_1269__SOLUTION1_H_
