/**
 * @author ooooo
 * @date 2021/3/6 13:05 
 */

#ifndef CPP_0503__SOLUTION1_H_
#define CPP_0503__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 单调栈 ，底部元素最大
class Solution {
 public:
	vector<int> nextGreaterElements(vector<int> &nums) {
		stack<int> s;
		int n = nums.size();
		vector<int> ans(n, -1);

		// 对最后一个元素特殊处理
		for (int i = n - 2; i >= 0; --i) {
			while (!s.empty() && nums[i] >= s.top()) {
				s.pop();
			}
			s.push(nums[i]);
		}

		for (int i = n - 1; i >= 0; --i) {
			while (!s.empty() && nums[i] >= s.top()) {
				s.pop();
			}
			if (!s.empty()) {
				ans[i] = s.top();
			}
			s.push(nums[i]);
		}
		return ans;
	}
};

#endif //CPP_0503__SOLUTION1_H_
