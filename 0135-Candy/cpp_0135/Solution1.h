/**
 * @author ooooo
 * @date 2020/12/24 14:16 
 */

#ifndef CPP_0135__SOLUTION1_H_
#define CPP_0135__SOLUTION1_H_

#include <iostream>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:
	int candy(vector<int> &ratings) {
		map<int, vector<int>> rate_map;
		int n = ratings.size();
		for (int i = 0; i < n; ++i) {
			rate_map[ratings[i]].push_back(i);
		}
		vector<int> candy(n, 0);
		for (auto &[k, v]: rate_map) {
			for (int i = 0; i < v.size(); ++i) {
				int cur_index = v[i];
				int left_index = v[i] - 1, right_index = v[i] + 1;
				candy[cur_index] = 1;
				if (left_index >= 0 && ratings[cur_index] > ratings[left_index]) {
					candy[cur_index] = max(candy[cur_index], candy[left_index] + 1);
				}
				if (right_index <= n-1 && ratings[cur_index] > ratings[right_index]) {
					candy[cur_index] = max(candy[cur_index], candy[right_index] + 1);
				}
			}
		}
		return accumulate(candy.begin(), candy.end(), 0);
	}
};

#endif //CPP_0135__SOLUTION1_H_
