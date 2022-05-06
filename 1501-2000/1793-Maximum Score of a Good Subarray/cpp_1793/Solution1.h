/**
 * @author ooooo
 * @date 2021/3/28 12:14 
 */

#ifndef CPP_1793__SOLUTION1_H_
#define CPP_1793__SOLUTION1_H_

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

	int maximumScore(vector<int> &nums, int k) {
		int n = nums.size();
		int ans = 0;
		int i = k, j = k;
		int minValue = nums[k];
		while (i >= 0 && j < n) {
			ans = max(ans, minValue * (j - i + 1));
			if (i - 1 >= 0 && j + 1 < n) {
				if (nums[i - 1] <= nums[j + 1]) {
					minValue = min(minValue, nums[j + 1]);
					j++;
				} else {
					minValue = min(minValue, nums[i - 1]);
					i--;
				}
			} else {
				break;
			}
		}
		int p = i, q = j;
		while (i >= 0) {
			minValue = min(minValue, nums[i]);
			ans = max(ans, minValue * (q - i + 1));
			i--;
		}
		while (j < n) {
			minValue = min(minValue, nums[j]);
			ans = max(ans, minValue * (j - p + 1));
			j++;
		}
		return ans;
	}

};

#endif //CPP_1793__SOLUTION1_H_
