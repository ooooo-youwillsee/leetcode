/**
 * @author ooooo
 * @date 2020/12/26 12:01 
 */

#ifndef CPP_1673__SOLUTION1_H_
#define CPP_1673__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:
	vector<int> mostCompetitive(vector<int> &nums, int k) {
		stack<int> stack;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (!stack.empty() && stack.top() > nums[i] && (n - i + stack.size() - 1) >= k) {
				stack.pop();
			}
			stack.push(nums[i]);
			if (stack.size() > k) {
				stack.pop();
			}
		}
		vector<int> ans(k);
		for (int i = k - 1; i >= 0; --i) {
			ans[i] = stack.top();
			stack.pop();
		}
		return ans;
	}
};

#endif //CPP_1673__SOLUTION1_H_
