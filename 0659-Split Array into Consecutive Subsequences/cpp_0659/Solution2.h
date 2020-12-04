/**
 * @author ooooo
 * @date 2020/12/4 21:35 
 */

#ifndef CPP_0659__SOLUTION2_H_
#define CPP_0659__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	bool isPossible(vector<int> &nums) {
		// key是以x结尾的子序列， value是子序列长度的最小堆
		unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
		for (auto &x: nums) {
			if (m.find(x - 1) != m.end()) {
				auto min_len = m[x - 1].top();
				m[x - 1].pop();
				if (m[x - 1].empty()) {
					m.erase(x - 1);
				}
				m[x].push(min_len + 1);
			} else {
				m[x].push(1);
			}
		}

		for (auto &[k, v] :m) {
			if (v.top() < 3) return false;
		}
		return true;
	}
};

#endif //CPP_0659__SOLUTION2_H_
