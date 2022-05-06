/**
 * @author ooooo
 * @date 2021/1/24 18:09 
 */

#ifndef CPP_1702__SOLUTION1_H_
#define CPP_1702__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution2 {

	string maximumBinaryString(string b) {
		int n = b.size();
		int cnt_0 = 0;
		for (auto c: b) {
			if (c == '0') cnt_0++;
		}
		int prev_is_1 = 0;
		for (auto c: b) {
			if (c == '0') {
				break;
			}
			prev_is_1++;
		}
		int last_is_1 = n - cnt_0 - prev_is_1;
		string ans(prev_is_1, '1');
		if (cnt_0 > 0) {
			ans += string(cnt_0 - 1, '1') + '0';
		}
		ans += string(last_is_1, '1');
		return ans;
	}
};

#endif //CPP_1702__SOLUTION1_H_
