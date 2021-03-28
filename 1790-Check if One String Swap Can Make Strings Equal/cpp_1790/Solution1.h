/**
 * @author ooooo
 * @date 2021/3/28 12:10 
 */

#ifndef CPP_1790__SOLUTION1_H_
#define CPP_1790__SOLUTION1_H_

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

	bool areAlmostEqual(string s1, string s2) {
		int n = s1.size();
		int swap1 = -1;
		for (int i = 0; i < n; ++i) {
			if (s1[i] != s2[i]) {
				swap1 = i;
				break;
			}
		}

		int swap2 = -1;
		for (int i = n - 1; i >= 0; --i) {
			if (s1[i] != s2[i]) {
				swap2 = i;
				break;
			}
		}
		if (swap1 != -1) {
			swap(s1[swap1], s1[swap2]);
			return s1 == s2;
		}
		return true;
	}
};

#endif //CPP_1790__SOLUTION1_H_
