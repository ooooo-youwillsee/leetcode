/**
 * @author ooooo
 * @date 2021/6/3 10:41 
 */

#ifndef CPP_0525__SOLUTION1_H_
#define CPP_0525__SOLUTION1_H_

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:

	// sum[i] 表示 0 到 i 的前缀和
	// sum[j] - sum[i] = (j -i) / 2
	// 2 * sum[j] - j = 2 * sum[i] - i && （j - i) % 2  == 0
	int findMaxLength(vector<int> &nums) {
		int n = nums.size();
		if (n < 2) return 0;
		int ans = 0;
		unordered_map<int, int> m;
		// 依据 [0，1] 推导这个初始值
		m[1] = -1;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			int a = 2 * sum - i;
			if (m.find(a) != m.end() && (i - m[a]) % 2 == 0) {
				ans = max(ans, i - m[a]);
			} else {
				// 如果不存在，就加入，如果存在，只保留最前面的
				m[a] = i;
			}
		}
		return ans;
	}
};
#endif //CPP_0525__SOLUTION1_H_
