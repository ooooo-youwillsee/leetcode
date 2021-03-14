/**
 * @author ooooo
 * @date 2021/3/14 15:00 
 */

#ifndef CPP_1784__SOLUTION1_H_
#define CPP_1784__SOLUTION1_H_

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

	bool checkOnesSegment(string s) {
		int n = s.size();
		int l = 0, r = n - 1;
		while (l <= r && s[l] == '0') {
			l++;
		}

		while (l <= r && s[r] == '0') {
			r--;
		}

		if (s[r] != '1' || s[l] != '1') {
			return false;
		}

		for (int i = l; i <= r; ++i) {
			if (s[i] == '0') {
				return false;
			}
		}
		return true;
	}

};

#endif //CPP_1784__SOLUTION1_H_
