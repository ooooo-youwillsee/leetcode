/**
 * @author ooooo
 * @date 2021/2/21 19:05 
 */

#ifndef CPP_1758__SOLUTION1_H_
#define CPP_1758__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int help(string s) {
		int count = 0;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == s[i - 1]) {
				s[i] = s[i - 1] == '0' ? '1' : '0';
				count++;
			}
		}
		return count;
	}

	int minOperations(string s) {
		int ans = 0;
		if (s[0] == '0') {
			ans = min(help(s), help('0' + s));
		} else {
			ans = min(help(s), help('1' + s));
		}
		return ans;
	}
};

#endif //CPP_1758__SOLUTION1_H_
