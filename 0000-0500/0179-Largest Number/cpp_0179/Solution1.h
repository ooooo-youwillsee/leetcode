/**
 * @author ooooo
 * @date 2021/4/12 17:16 
 */

#ifndef CPP_0179__SOLUTION1_H_
#define CPP_0179__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	string largestNumber(vector<int> &nums) {
		int n = nums.size();
		vector<string> s;
		for (int i = 0; i < n; i++) {
			string numStr = to_string(nums[i]);
			s.push_back(numStr);
		}
		sort(s.begin(), s.end(), [&](const auto &s1, const auto &s2) {
			return s2 + s1 < s1 + s2;
		});
		string ans = "";
		for (int i = 0; i < n; i++) {
			ans += s[i];
		}
		if (ans[0] == '0') return "0";
		return ans;
	}
};

#endif //CPP_0179__SOLUTION1_H_
