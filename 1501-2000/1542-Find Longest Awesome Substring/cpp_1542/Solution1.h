/**
 * @author ooooo
 * @date 2021/4/6 14:58 
 */

#ifndef CPP_1542__SOLUTION1_H_
#define CPP_1542__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int longestAwesome(string s) {
		int x = 0;
		int n = s.size();
		unordered_map<int, int> m = {{0, -1}};
		int ans = 0;
		for (int i = 0; i < n; i++) {
			x ^= 1 << (s[i] - '0');
			if (m.find(x) != m.end()) {
				ans = max(ans, i - m[x]);
			} else {
				m[x] = i;
			}
			for (int j = 0; j < 10; j++) {
				int y = x ^(1 << j);
				if (m.find(y) != m.end()) {
					ans = max(ans, i - m[y]);
				}
			}
		}
		return ans;
	}
};

#endif //CPP_1542__SOLUTION1_H_
