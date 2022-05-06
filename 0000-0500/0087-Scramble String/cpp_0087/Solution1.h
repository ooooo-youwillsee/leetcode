/**
 * @author ooooo
 * @date 2021/5/7 20:08 
 */

#ifndef CPP_0087__SOLUTION1_H_
#define CPP_0087__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	bool dfs(string &s1, string &s2, int i, int j, int len) {
		if (memo[i][j][len] != 0) return memo[i][j][len] == 1;
		if (s1.substr(i, len) == s2.substr(j, len)) return true;
		for (int cnt = 1; cnt < len; cnt++) {
			bool flag = dfs(s1, s2, i, j, cnt) && dfs(s1, s2, i + cnt, j + cnt, len - cnt);
			flag = flag || dfs(s1, s2, i, j + len - cnt, cnt) && dfs(s1, s2, i + cnt, j, len - cnt);
			if (flag) {
				memo[i][j][len] = 1;
				return true;
			}
		}
		memo[i][j][len] = -1;
		return false;
	}

	int memo[35][35][35];
	bool isScramble(string s1, string s2) {
		memset(memo, 0, sizeof(memo)); // 0 表示没有计算过, 1 表示true， -1 表示false
		return dfs(s1, s2, 0, 0, s1.size());
	}
};

#endif //CPP_0087__SOLUTION1_H_
