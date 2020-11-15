/**
 * @author ooooo
 * @date 2020/11/15 09:35 
 */

#ifndef CPP_1641__SOLUTION1_H_
#define CPP_1641__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <numeric>
#include <stack>
#include <queue>

using namespace std;

class Solution {
 public:
	int countVowelStrings(int n) {
		vector<int> nums = {1, 1, 1, 1, 1};
		while (n > 1) {
			for (int i = nums.size() - 2; i >= 0; i--) {
				nums[i] += nums[i + 1];
			}
			n--;
		}
		return accumulate(nums.begin(), nums.end(), 0);
	}
};

#endif //CPP_1641__SOLUTION1_H_
