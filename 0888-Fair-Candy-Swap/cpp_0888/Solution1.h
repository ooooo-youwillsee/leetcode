/**
 * @author ooooo
 * @date 2020/9/30 15:42 
 */

#ifndef CPP_0888__SOLUTION1_H_
#define CPP_0888__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
 public:
	vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
		int sum_a = accumulate(A.begin(), A.end(), 0), sum_b = accumulate(B.begin(), B.end(), 0);
		unordered_set<int> s(B.begin(), B.end());
		int diff = (sum_a + sum_b) / 2 - sum_a;
		for (auto &item: A) {
			if (s.find(item + diff) != s.end()) return {item, item + diff};
		}
		return {};
	}
};

#endif //CPP_0888__SOLUTION1_H_
