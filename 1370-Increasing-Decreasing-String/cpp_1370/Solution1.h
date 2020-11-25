/**
 * @author ooooo
 * @date 2020/11/25 09:13 
 */

#ifndef CPP_1370__SOLUTION1_H_
#define CPP_1370__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	string sortString(string s) {
		vector<int> count(26);
		for (auto &c :s) {
			count[c - 'a']++;
		}
		int n = s.size(), i = 0, step = 1;
		string ans = "";
		while (n > 0) {
			if (count[i] > 0) {
				ans.push_back(i + 'a');
				n--;
				count[i]--;
			}
			i += step;
			if (i >= count.size() || i < 0) {
				step = -step;
				i += step;
			}
		}
		return ans;
	}
};

#endif //CPP_1370__SOLUTION1_H_
