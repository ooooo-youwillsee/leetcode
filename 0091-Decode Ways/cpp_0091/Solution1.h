/**
 * @author ooooo
 * @date 2021/4/21 14:03 
 */

#ifndef CPP_0091__SOLUTION1_H_
#define CPP_0091__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:

	int dfs(string &s, int i) {
		if (memo.find(i) != memo.end()) return memo[i];
		if (i == s.size()) return 1;
		// 如果当前字符为’0‘，不可能构成字母，返回0
		if (s[i] == '0') return 0;
		int ans = 0;
		// 分情况讨论， 如果后一位为0，那么必须和前面一位构成10，20，其他不可能构成字母，返回0
		if (i + 1 < s.size() && s[i+1] == '0') {
			int num = stoi(s.substr(i, 2));
			if (num == 20 || num == 10) {
				ans += dfs(s, i+2);
			}else {
				ans = 0;
			}
		}else {
			// 正常情况判断，
			ans += dfs(s, i+1);
			if (i + 1 < s.size()) {
				if (stoi(s.substr(i, 2)) <= 26) {
					ans += dfs(s, i+2);
				}
			}
		}
		return memo[i] = ans;
	}
	// 记忆化
	unordered_map<int,int> memo;
	int numDecodings(string s) {
		return dfs(s, 0);
	}
};

#endif //CPP_0091__SOLUTION1_H_
