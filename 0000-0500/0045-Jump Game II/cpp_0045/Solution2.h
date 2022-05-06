/**
 * @author ooooo
 * @date 2021/6/4 20:21 
 */

#ifndef CPP_0045__SOLUTION2_H_
#define CPP_0045__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 从0到n-1 循环获取，贪心
 */
class Solution {
 public:
	int jump(vector<int> &nums) {
		int n = nums.size();
		int last = n - 1;
		int ans = 0;
		while (last > 0) {
			for (int i = 0; i < last; i++) {
				if (nums[i] + i >= last) {
					last = i;
					ans++;
					break;
				}
			}
		}
		return ans;
	}
};

#endif //CPP_0045__SOLUTION2_H_
