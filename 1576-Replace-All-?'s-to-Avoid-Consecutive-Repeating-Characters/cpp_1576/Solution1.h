/**
 * @author ooooo
 * @date 2020/9/7 13:14 
 */

#ifndef CPP_1576__SOLUTION1_H_
#define CPP_1576__SOLUTION1_H_

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:

	bool dfs(string &s, int i) {
		if (i == s.length()) return true;
		if (s[i] != '?' && dfs(s, i + 1)) return true;
		for (int j = 0; j < 26; ++j) {
			char c = j + 'a';
			if (s[i - 1] != c && s[i + 1] != c) {
				s[i] = c;
				if (dfs(s, i + 1)) return true;
				s[i] = '?';
			}
		}
		return false;
	}

	string modifyString(string s) {
		s = '$' + s + '$';
		dfs(s, 1);
		s = s.substr(1, s.size() - 2);
		return s;
	}
};
#endif //CPP_1576__SOLUTION1_H_
