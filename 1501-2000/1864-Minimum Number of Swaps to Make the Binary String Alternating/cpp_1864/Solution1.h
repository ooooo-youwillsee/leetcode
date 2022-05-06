/**
 * @author ooooo
 * @date 2021/5/25 22:16 
 */

#ifndef CPP_1864__SOLUTION1_H_
#define CPP_1864__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {

 public:
	int cntSwap(string &s, char startC) {
		int diffCnt = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != startC) {
				diffCnt++;
			}
			startC = '1' == startC ? '0' : '1';
		}
		if (diffCnt % 2 == 1) {
			return INT_MAX;
		}
		return max(0, diffCnt / 2);
	}
	int minSwaps(string s) {
		if (s.size() <= 1) return 0;
		int cnt0 = 0, cnt1 = 0;
		for (auto c: s) {
			if (c == '1') {
				cnt1++;
			} else {
				cnt0++;
			}
		}
		if (abs(cnt1 - cnt0) > 1) return -1;

		int ans = min(cntSwap(s, '1'), cntSwap(s, '0'));
		return ans;
	}
};
#endif //CPP_1864__SOLUTION1_H_
