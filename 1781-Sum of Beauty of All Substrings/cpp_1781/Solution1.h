/**
 * @author ooooo
 * @date 2021/3/14 14:57 
 */

#ifndef CPP_1781__SOLUTION1_H_
#define CPP_1781__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:

	int beautySum(string s) {
		int ans = 0;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			int l = 0, r = i;
			vector<int> m(26);
			int cnt = 0, maxReq = INT_MIN;
			while (r < n) {
				m[s[r] - 'a']++;
				if (m[s[r] - 'a'] == 1) {
					cnt++;
				}
				maxReq = max(maxReq, m[s[r] - 'a']);
				int minReq = INT_MAX;
				for (int j = 0; j < 26; ++j) {
					if (m[j] > 0) {
						minReq = min(minReq, m[j]);
					}
				}
				ans += (maxReq - minReq);
				r++;
			}
		}
		return ans;
	}
};

#endif //CPP_1781__SOLUTION1_H_
