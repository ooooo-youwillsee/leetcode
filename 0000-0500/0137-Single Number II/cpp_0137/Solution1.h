/**
 * @author ooooo
 * @date 2021/4/30 20:02 
 */

#ifndef CPP_0137__SOLUTION1_H_
#define CPP_0137__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
 public:
	int singleNumber(vector<int> &nums) {
		unordered_map<int, int> m;
		for (auto num: nums) {
			m[num]++;
		}
		for (auto &e: m) {
			if (e.second == 1) return e.first;
		}
		return -1;
	}
};

#endif //CPP_0137__SOLUTION1_H_
