/**
 * @author ooooo
 * @date 2021/3/24 16:38 
 */

#ifndef CPP_0456__SOLUTION2_H_
#define CPP_0456__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// o(n)
class Solution {
 public:
	bool find132pattern(vector<int> &nums) {
		int n = nums.size();
		if (n < 3) {
			return false;
		}
		stack<int> maxStack;
		int last = INT_MIN;
		for (int i = n - 1; i >= 0; --i) {
			if (nums[i] < last) {
				return true;
			}
			while (!maxStack.empty() && maxStack.top() < nums[i]) {
				last = maxStack.top();
				maxStack.pop();
			}
			maxStack.push(nums[i]);
		}
		return false;
	}
};

#endif //CPP_0456__SOLUTION2_H_
