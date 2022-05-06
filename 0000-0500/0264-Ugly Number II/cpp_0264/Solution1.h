/**
 * @author ooooo
 * @date 2021/4/11 15:12 
 */

#ifndef CPP_0264__SOLUTION1_H_
#define CPP_0264__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;

class Solution {
 public:

	vector<int> nums = {2, 3, 5};

	using ll = long long;
	int nthUglyNumber(int n) {
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		unordered_set<ll> set;
		pq.push(1);
		int i = 0;
		while (!pq.empty()) {
			ll x = pq.top();
			pq.pop();
			if (!set.count(x)) {
				i++;
				set.insert(x);
				for (int k = 0; k < 3; k++) {
					pq.push(nums[k] * x);
				}
				if (i == n) {
					return x;
				}
			}
		}
		return 0;
	}
};

#endif //CPP_0264__SOLUTION1_H_
