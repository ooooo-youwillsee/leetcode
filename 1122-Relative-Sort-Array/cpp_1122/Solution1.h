/**
 * @author ooooo
 * @date 2020/11/14 20:22 
 */

#ifndef CPP_1122__SOLUTION1_H_
#define CPP_1122__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
		unordered_map<int, int> indexes_map;
		for (int i = 0; i < arr2.size(); ++i) {
			indexes_map[arr2[i]] = i;
		}
		vector<int> ans, other;
		for (auto &item: arr1) {
			if (indexes_map.find(item) != indexes_map.end()) {
				ans.push_back(item);
			} else {
				other.push_back(item);
			}
		}

		sort(ans.begin(), ans.end(), [&](int x, int y) {
			return indexes_map[x] < indexes_map[y];
		});
		sort(other.begin(), other.end());
		ans.insert(ans.end(), other.begin(), other.end());
		return ans;
	}
};

#endif //CPP_1122__SOLUTION1_H_
