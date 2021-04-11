/**
 * @author ooooo
 * @date 2021/4/11 15:48 
 */

#ifndef CPP_1814__SOLUTION1_H_
#define CPP_1814__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {

	long long rev(long long num) {
		long long sum = 0;
		while (num) {
			sum = sum * 10 + num % 10;
			num /= 10;
		}
		return sum;
	}

	int countNicePairs(vector<int> &nums) {
		unordered_map<long long, long long> m;
		for (auto num : nums) {
			m[rev(num) - num]++;
		}

		long long ans = 0;
		int mod = 1e9 + 7;
		for (auto &e: m) {
			if (e.second >= 2) {
				ans = (ans + e.second * (e.second - 1) / 2) % mod;
			}
		}
		return ans;
	}
};

#endif //CPP_1814__SOLUTION1_H_
