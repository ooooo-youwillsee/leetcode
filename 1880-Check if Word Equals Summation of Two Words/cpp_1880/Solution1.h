/**
 * @author ooooo
 * @date 2021/5/31 10:15 
 */

#ifndef CPP_1880__SOLUTION1_H_
#define CPP_1880__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	long long help(string &s) {
		long long ans = 0;
		for (auto c : s) {
			ans = ans * 10 + (c - 'a');
		}
		return ans;
	}
	bool isSumEqual(string a, string b, string c) {
		return help(a) == help(c) - help(b);

	}
};

#endif //CPP_1880__SOLUTION1_H_
