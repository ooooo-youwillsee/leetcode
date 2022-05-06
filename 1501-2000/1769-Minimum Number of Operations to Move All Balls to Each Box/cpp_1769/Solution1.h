/**
 * @author ooooo
 * @date 2021/2/28 13:21 
 */

#ifndef CPP_1769__SOLUTION1_H_
#define CPP_1769__SOLUTION1_H_

#include <vector>
#include <iostream>

using namespace  std;

class Solution {

	vector<int> minOperations(string boxes) {
		int n = boxes.size();
		vector<int> left(n, 0), right(n, 0);
		vector<int> leftCount(n, 0), rightCount(n, 0);
		leftCount[0] = boxes[0] - '0';
		rightCount[n - 1] = boxes[n - 1] - '0';
		for (int i = 1; i < n; ++i) {
			leftCount[i] = leftCount[i - 1] + boxes[i] - '0';
			left[i] = left[i - 1] + leftCount[i - 1];
		}
		for (int i = n - 2; i >= 0; --i) {
			rightCount[i] = rightCount[i + 1] + boxes[i] - '0';
			right[i] = right[i + 1] + rightCount[i + 1];
		}

		vector<int> ans(n, 0);
		for (int i = 0; i < n; ++i) {
			ans[i] = left[i] + right[i];
		}
		return ans;
	}
};

#endif //CPP_1769__SOLUTION1_H_
