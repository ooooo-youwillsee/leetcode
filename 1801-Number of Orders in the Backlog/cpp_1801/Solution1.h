/**
 * @author ooooo
 * @date 2021/3/28 12:18 
 */

#ifndef CPP_1801__SOLUTION1_H_
#define CPP_1801__SOLUTION1_H_

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

	typedef pair<int, int> pii;
	int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
		int MOD = 1e9 + 7;
		priority_queue<pii> buyMaxHeap;
		priority_queue<pii, vector<pii>, greater<pii>> sellMinHeap;
		for (auto &v : orders) {
			if (v[2] == 0) {
				while (!sellMinHeap.empty() && sellMinHeap.top().first <= v[0]) {
					int p = sellMinHeap.top().first;
					v[1] -= sellMinHeap.top().second;
					sellMinHeap.pop();
					if (v[1] < 0) {
						sellMinHeap.emplace(p, -v[1]);
						break;
					}
				}
				if (v[1] > 0) {
					buyMaxHeap.emplace(v[0], v[1]);
				}
			} else if (v[2] == 1) {
				while (!buyMaxHeap.empty() && buyMaxHeap.top().first >= v[0]) {
					int p = buyMaxHeap.top().first;
					v[1] -= buyMaxHeap.top().second;
					buyMaxHeap.pop();
					if (v[1] < 0) {
						buyMaxHeap.emplace(p, -v[1]);
						break;
					}
				}
				if (v[1] > 0) {
					sellMinHeap.emplace(v[0], v[1]);
				}
			}
		}

		long long ans = 0;
		while (!sellMinHeap.empty()) {
			ans = (ans + sellMinHeap.top().second) % MOD;
			sellMinHeap.pop();
		}
		while (!buyMaxHeap.empty()) {
			ans = (ans + buyMaxHeap.top().second) % MOD;
			buyMaxHeap.pop();
		}
		return ans;
	}
};

#endif //CPP_1801__SOLUTION1_H_
