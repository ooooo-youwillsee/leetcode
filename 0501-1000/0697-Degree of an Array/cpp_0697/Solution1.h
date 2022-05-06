/**
 * @author ooooo
 * @date 2021/2/20 09:36 
 */

#ifndef CPP_0697__SOLUTION1_H_
#define CPP_0697__SOLUTION1_H_

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int findShortestSubArray(vector<int> &nums) {
		// count, start, end
		vector<vector<int>> m(50001, {0, -1, -1});
		int count = 0;
		vector<int> maxNums;
		for (int i = 0; i < nums.size(); ++i) {
			int num = nums[i];
			m[num][0] +=1;
			if (m[num][1] == -1) {
				m[num][1] = m[num][2] = i;
			}
			if (m[num][0] > count) {
				count = m[num][0];
				maxNums.clear();
				maxNums.push_back(num);
				m[num][2] = i;
			} else if (m[num][0] == count) {
				maxNums.push_back(num);
				m[num][2] = i;
			}
		}

		int ans = nums.size();
		for (int i = 0; i < maxNums.size(); ++i) {
			ans = min(ans, m[maxNums[i]][2] - m[maxNums[i]][1]);
		}
		return ans;
	}
};

#endif //CPP_0697__SOLUTION1_H_
