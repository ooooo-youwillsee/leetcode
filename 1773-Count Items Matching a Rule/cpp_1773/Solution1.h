/**
 * @author ooooo
 * @date 2021/3/14 14:52 
 */

#ifndef CPP_1773__SOLUTION1_H_
#define CPP_1773__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:

	int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue) {
		int ans = 0;
		for (auto &item: items) {
			if (ruleKey == "type" && ruleValue == item[0]) {
				ans++;
			} else if (ruleKey == "color" && ruleValue == item[1]) {
				ans++;
			} else if (ruleKey == "name" && ruleValue == item[2]) {
				ans++;
			}
		}
		return ans;
	}
};

#endif //CPP_1773__SOLUTION1_H_
