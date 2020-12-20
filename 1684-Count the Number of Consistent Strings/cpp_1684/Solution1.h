/**
 * @author ooooo
 * @date 2020/12/20 13:03 
 */

#ifndef CPP_1684__SOLUTION1_H_
#define CPP_1684__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	int countConsistentStrings(string allowed, vector<string> &words) {
		int ans = 0;
		unordered_set<char> set(allowed.begin(), allowed.end());
		for (auto &word: words) {
			bool flag = true;
			for (auto &c: word) {
				if (!set.count(c)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				ans++;
			}
		}
		return ans;
	}
};

#endif //CPP_1684__SOLUTION1_H_
