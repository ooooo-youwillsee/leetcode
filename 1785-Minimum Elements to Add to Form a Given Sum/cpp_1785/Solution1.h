/**
 * @author ooooo
 * @date 2021/3/14 15:01 
 */

#ifndef CPP_1785__SOLUTION1_H_
#define CPP_1785__SOLUTION1_H_

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

	int minElements(vector<int> &nums, int limit, int goal) {
		long long sum = accumulate(nums.begin(), nums.end(), (long long) 0);
		long long target = abs(goal - sum);
		if (target == 0) {
			return 0;
		}
		return target % limit == 0 ? target / limit : target / limit + 1;
	}
};

#endif //CPP_1785__SOLUTION1_H_
