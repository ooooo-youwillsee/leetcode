/**
 * @author ooooo
 * @date 2021/4/4 09:04 
 */

#ifndef CPP_0781__SOLUTION1_H_
#define CPP_0781__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int numRabbits(vector<int> &answers) {
		unordered_map<int, int> m;
		int ans = 0;
		for (auto i: answers) {
			m[i]++;
		}
		for (auto &e: m) {
			int cnt = 0;
			if (e.second % (e.first + 1) == 0) {
				cnt = e.second / (e.first + 1);
			} else {
				cnt = e.second / (e.first + 1) + 1;
			}
			ans += cnt * (e.first + 1);
		}
		return ans;
	}
};

#endif //CPP_0781__SOLUTION1_H_
