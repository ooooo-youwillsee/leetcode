/**
 * @author ooooo
 * @date 2020/9/26 17:23 
 */

#ifndef CPP_018__SOLUTION1_H_
#define CPP_018__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int breakfastNumber(vector<int> &staple, vector<int> &drinks, int x) {
		sort(staple.begin(), staple.end());
		sort(drinks.begin(), drinks.end());
		int ans = 0;
		for (auto &item: staple) {
			auto it = upper_bound(drinks.begin(), drinks.end(), x - item);
			ans = (it - drinks.begin() + ans) % 1000000007;
		}

		return ans;
	}
};

#endif //CPP_018__SOLUTION1_H_
