/**
 * @author ooooo
 * @date 2020/9/7 14:56 
 */

#ifndef CPP_1576__SOLUTION2_H_
#define CPP_1576__SOLUTION2_H_

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:

	string modifyString(string s) {
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != '?') continue;
			char c = 'a';
			for (int j = 0; j < 26; ++j) {
				c += j;
				if (((i > 0 && c != s[i - 1]) || i == 0) && ((i + 1 < s.size() && c != s[i + 1]) || i == s.size() - 1)) {
					s[i] = c;
					break;
				}
			}
		}
		return s;
	}
};

#endif //CPP_1576__SOLUTION2_H_
