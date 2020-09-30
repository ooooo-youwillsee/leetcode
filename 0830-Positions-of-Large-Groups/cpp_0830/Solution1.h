/**
 * @author ooooo
 * @date 2020/9/30 09:30 
 */

#ifndef CPP_0830__SOLUTION1_H_
#define CPP_0830__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	vector<vector<int>> largeGroupPositions(string s) {
		vector<vector<int>> ans;
		int prev = 0, cur = 0;
		while (cur < s.size()) {
			if (cur == s.size() - 1 || s[cur] != s[cur + 1]) {
				if (cur - prev >= 2) {
					ans.push_back({prev, cur});
				}
				prev = cur + 1;
			}
			cur++;
		}

		return ans;
	}
};

#endif //CPP_0830__SOLUTION1_H_
