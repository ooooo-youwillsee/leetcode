/**
 * @author ooooo
 * @date 2020/10/22 15:49 
 */

#ifndef CPP_0763__SOLUTION2_H_
#define CPP_0763__SOLUTION2_H_


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	vector<int> partitionLabels(string s) {
		vector<int> ans;
		int l = 0, r = 0;
		unordered_map<char, int> char_indexes;
		for (int i = 0; i < s.size(); ++i) {
			char_indexes[s[i]] = i;
		}
		while (l < s.size()) {
			int prev = l;
			while (l <= r) {
				r = max(r, char_indexes[s[l]]);
				l++;
			}
			ans.push_back(l - prev);
			r = l;
		}
		return ans;
	}
};

#endif //CPP_0763__SOLUTION2_H_
