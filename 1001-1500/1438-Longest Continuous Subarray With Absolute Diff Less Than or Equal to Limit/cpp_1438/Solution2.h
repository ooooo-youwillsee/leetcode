/**
 * @author ooooo
 * @date 2021/2/21 09:14 
 */

#ifndef CPP_1438__SOLUTION2_H_
#define CPP_1438__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// 单调队列维护区间的最值
class Solution {
 public:
	int longestSubarray(vector<int> &nums, int limit) {
		int l = 0, r = 0;
		int ans = 0;
		deque<int> maxQ, minQ;

		while (r < nums.size()) {

			// 维护最小值下标
			while (!minQ.empty() && nums[minQ.back()] >= nums[r]) {
				minQ.pop_back();
			}
			minQ.push_back(r);

			// 维护最大值下标
			while (!maxQ.empty() && nums[maxQ.back()] <= nums[r]) {
				maxQ.pop_back();
			}
			maxQ.push_back(r);

			while (nums[maxQ.front()] - nums[minQ.front()] > limit) {
				if (maxQ.front() == l) {
					maxQ.pop_front();
				}
				if (minQ.front() == l) {
					minQ.pop_front();
				}
				l++;
			}
			r++;
			ans = max(ans, r - l);
		}
		return ans;
	}
};

#endif //CPP_1438__SOLUTION2_H_
