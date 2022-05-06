/**
 * @author ooooo
 * @date 2021/3/28 12:19 
 */

#ifndef CPP_1802__SOLUTION1_H_
#define CPP_1802__SOLUTION1_H_


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

	int maxValue(int n, int index, int maxSum) {
		int l = 1, r = maxSum;
		int ans = 0;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (check(mid, index, n, maxSum)) {
				l = mid + 1;
				ans = mid;
			} else {
				r = mid - 1;
			}
		}
		return ans;
	}

	bool check(long long mid, long long index, long long n, long long target) {
		long long sum = mid;
		if (index < mid - 1) {
			sum += (mid - index + mid - 1) * index / 2;
		} else if (index >= mid - 1) {
			sum += (index - mid + 1) + (1 + mid - 1) * (mid - 1) / 2;
		}

		if (n - index - 1 < mid - 1) {
			sum += (mid - n + index + 1 + mid - 1) * (n - index - 1) / 2;
		} else {
			sum += (n - index - 1 - mid + 1) + (1 + mid - 1) * (mid - 1) / 2;
		}
		return sum <= target;
	}

};
#endif //CPP_1802__SOLUTION1_H_
