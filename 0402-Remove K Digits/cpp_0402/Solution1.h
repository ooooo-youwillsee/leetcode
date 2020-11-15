/**
 * @author ooooo
 * @date 2020/11/15 09:51 
 */

#ifndef CPP_0402__SOLUTION1_H_
#define CPP_0402__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	string removeKdigits(string num, int k) {
		if (k == num.size()) return "0";
		vector<char> vec;
		for (int i = 0; i < num.size(); ++i) {
			while (!vec.empty() && vec.back() > num[i] && k) {
				vec.pop_back();
				k--;
			}
			vec.push_back(num[i]);
		}
		// 都是递增的，删除最后面的元素
		while (k) {
			vec.pop_back();
			k--;
		}
		string ans = "";
		bool prevHasNum = false;
		for (int i = 0; i < vec.size(); ++i) {
			if (vec[i] == '0' && !prevHasNum) {
				continue;
			}
			ans.push_back(vec[i]);
			prevHasNum = true;
		}
		return ans == "" ? "0" : ans;
	}

};
#endif //CPP_0402__SOLUTION1_H_
