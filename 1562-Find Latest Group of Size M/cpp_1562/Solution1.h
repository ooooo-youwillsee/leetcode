/**
 * @author ooooo
 * @date 2020/12/12 18:33 
 */

#ifndef CPP_1562__SOLUTION1_H_
#define CPP_1562__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
	int findLatestStep(vector<int> &arr, int m) {
		int n = arr.size();
		if (m == n) return n;
		set<int> insert = {0, n + 1};
		for (int i = n - 1; i >= 0; --i) {
			int k = arr[i];
			auto it = insert.lower_bound(k);
			if (k - *prev(it) - 1 == m || *it - k - 1 == m) return i;
			insert.insert(k);
		}
		return -1;
	}
};

#endif //CPP_1562__SOLUTION1_H_
