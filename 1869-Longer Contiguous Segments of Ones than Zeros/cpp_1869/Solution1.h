/**
 * @author ooooo
 * @date 2021/5/25 22:20 
 */

#ifndef CPP_1869__SOLUTION1_H_
#define CPP_1869__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
	int help(string &s, char c) {
		int cnt = 0;
		int max_cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == c) {
				cnt++;
			} else {
				max_cnt = max(max_cnt, cnt);
				cnt = 0;
			}
		}
		return max(max_cnt, cnt);
	}
	bool checkZeroOnes(string s) {
		return help(s, '1') > help(s, '0');
	}
};

#endif //CPP_1869__SOLUTION1_H_
