/**
 * @author ooooo
 * @date 2021/2/28 13:04 
 */

#ifndef CPP_1647__SOLUTION1_H_
#define CPP_1647__SOLUTION1_H_

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

	int minDeletions(string s) {
		unordered_map<int, int> map;
		int max_count = 0;
		for (auto &c: s) {
			map[c]++;
			max_count = max(max_count, map[c]);
		}
		vector<bool> flag(max_count + 1, false);
		int ans = 0;
		for (auto[k, v] : map) {
			if (!flag[v]) {
				flag[v] = true;
			} else {
				for (int i = v; i > 0; --i) {
					if (!flag[i]) {
						flag[i] = true;
						break;
					}
					ans++;
				}
			}
		}
		return ans;
	}
};

#endif //CPP_1647__SOLUTION1_H_
