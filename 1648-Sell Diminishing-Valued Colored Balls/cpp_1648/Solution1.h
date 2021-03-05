
/**
 * @author ooooo
 * @date 2021/3/5 11:11 
 */

#ifndef CPP_1648__SOLUTION1_H_
#define CPP_1648__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:

	static constexpr int MOD = 1000000007;

	int maxProfit(vector<int> &inventory, int orders) {
		long long l = 1, r = *max_element(inventory.begin(), inventory.end());
		long long pos = 0;
		while (l <= r) {
			long long mid = l + (r - l) / 2;
			if (check(mid, inventory, orders)) {
				pos = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		long long total = 0;
		for (int i = 0; i < inventory.size(); ++i) {
			long long v = inventory[i];
			if (v > pos) {
				total += (pos + 1 + v) * (inventory[i] - pos) / 2;
				orders -= (inventory[i] - pos);
			}
		}

		if (orders == 0) {
			return total % MOD;
		}
		return (total + orders * pos) % MOD;
	}

	bool check(long long mid, vector<int> &inventory, int orders) {
		long long sum = 0;
		for (int i = 0; i < inventory.size(); ++i) {
			long long v = inventory[i];
			if (v > mid) {
				sum += (v - mid);
			}
		}
		return sum <= orders;
	}

};

#endif //CPP_1648__SOLUTION1_H_
