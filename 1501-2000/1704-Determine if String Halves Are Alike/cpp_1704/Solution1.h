/**
 * @author ooooo
 * @date 2021/1/24 17:14 
 */

#ifndef CPP_1704__SOLUTION1_H_
#define CPP_1704__SOLUTION1_H_

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

	bool halvesAreAlike(string s) {
		int n = s.size();
		unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; ++i) {
			if (i < n / 2) {
				if (set.count(s[i])) {
					cnt1++;
				}
			} else {
				if (set.count(s[i])) {
					cnt2++;
				}
			}
		}
		return cnt1 == cnt2;
	}

};

#endif //CPP_1704__SOLUTION1_H_
