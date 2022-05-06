/**
 * @author ooooo
 * @date 2020/12/11 10:29 
 */

#ifndef CPP_1663__SOLUTION1_H_
#define CPP_1663__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	string getSmallestString(int n, int k) {
		string ans = "";
		for (int i = 0; i < n; ++i) {
			ans += 'a';
		}
		k -= n;
		int cnt = k / 25;
		int j = n - 1;
		for (int i = 0; i < cnt; ++i) {
			ans[j] = 'z';
			j--;
		}
		if (k % 25) {
			ans[j] = (k % 25) + 'a';
		}
		return ans;
	}
};

#endif //CPP_1663__SOLUTION1_H_
