/**
 * @author ooooo
 * @date 2020/9/30 14:19 
 */

#ifndef CPP_0874__SOLUTION1_H_
#define CPP_0874__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	vector<vector<int>> dx_dy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	struct pair_hash {
		size_t operator()(pair<int, int> __v) const {
			return hash<int>{}(__v.first) * 10 + hash<int>{}(__v.second);
		}
	};

	int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
		int d = 1;
		int x = 0, y = 0;
		int ans = 0;

		unordered_set<pair<int, int>, pair_hash> s;
		for (auto &item : obstacles) {
			s.insert(make_pair(item[0], item[1]));
		}

		for (auto &c : commands) {
			if (c == -1) {
				d = (d + 3) % 4;
			} else if (c == -2) {
				d = (d + 1) % 4;
			} else {
				for (int i = 1; i <= c; ++i) {
					int nx = x + dx_dy[d][0], ny = y + dx_dy[d][1];
					if (s.find(make_pair(nx, ny)) == s.end()) {
						x = nx;
						y = ny;
						ans = max(ans, x * x + y * y);
					} else {
						break;
					}
				}
			}
		}
		return ans;
	}
};

#endif //CPP_0874__SOLUTION1_H_
