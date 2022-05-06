/**
 * @author ooooo
 * @date 2020/12/11 11:16 
 */

#ifndef CPP_1672__SOLUTION1_H_
#define CPP_1672__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int maximumWealth(vector<vector<int>> &a) {
		int ans = 0;
		for (int i = 0; i < a.size(); i++) {
			ans = max(ans, accumulate(a[i].begin(), a[i].end(), 0));
		}
		return ans;
	}
};

#endif //CPP_1672__SOLUTION1_H_
