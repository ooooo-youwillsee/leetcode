/**
 * @author ooooo
 * @date 2021/2/27 12:18 
 */

#ifndef CPP_0424__SOLUTION1_H_
#define CPP_0424__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int characterReplacement(string s, int k) {
		int n = s.size();
		int l = 0, r = 0;
		int maxCnt = 0;
		int ans = 0;
		vector<int> m(26, 0);
		while (r < n) {
			m[s[r] - 'A']++;
			maxCnt = max(maxCnt, m[s[r] - 'A']);

			while (r - l + 1 - maxCnt > k) {
				m[s[l] - 'A']--;
				l++;
				int cnt = 0;
				for (int i = 0; i < 26; ++i) {
					cnt = max(m[i], cnt);
				}
				maxCnt = cnt;
			}
			ans = max(ans, r - l + 1);
			r++;
		}
		return ans;
	}
};

#endif //CPP_0424__SOLUTION1_H_
