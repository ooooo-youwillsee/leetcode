/**
 * @author ooooo
 * @date 2020/10/22 08:52 
 */

#ifndef CPP_0763__SOLUTION1_H_
#define CPP_0763__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	vector<int> partitionLabels(string s) {
		vector<int> ans;
		int l = 0, r = 0;
		while (l < s.size()) {
			int prev = l;
			while (l <= r) {
				for (int i = s.size() - 1; i >= l; ++l) {
					if (s[i] == s[l]) {
						r = max(r, i);
						break;
					}
				}
				l++;
			}
			ans.push_back(l - prev);
			r = l;
		}
		return ans;
	}
};

#endif //CPP_0763__SOLUTION1_H_
