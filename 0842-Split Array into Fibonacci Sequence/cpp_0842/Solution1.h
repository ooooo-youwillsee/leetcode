/**
 * @author ooooo
 * @date 2020/12/8 19:08 
 */

#ifndef CPP_0842__SOLUTION1_H_
#define CPP_0842__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
 public:

	long max_v = (int) (pow(2, 31) - 1);

	bool dfs(vector<int> &nums, string &s, int i) {
		if (i >= s.size()) return true;
		long next_num = (long) nums[nums.size() - 1] + (long) nums[nums.size() - 2];
		// 结果数超过最大值 返回false
		if (next_num > max_v) return false;
		string next = to_string(next_num);
		if (s.substr(i, next.size()) == next) {
			nums.push_back(next_num);
			if (dfs(nums, s, i + next.size())) return true;
			// 回溯
			nums.pop_back();
		}
		return false;
	}

	vector<int> splitIntoFibonacci(string s) {
		vector<int> nums;
		int max_v_len = to_string(max_v).size();
		int n = s.size();
		// 取第一个数和第二个数
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < n; ++j) {
				// 剪枝操作， n - i - j 表示剩余数的长度至少为 max(i, j)
				if (i > max_v_len || j > max_v_len || n - i - j < max(i, j)) {
					continue;
				}
				long first = stol(s.substr(0, i));
				long second = stol(s.substr(i, j));
				// 有一个数超过最大值 continue
				if (first > max_v || second > max_v || first + second > max_v) continue;
				nums.push_back(first);
				nums.push_back(second);
				// 有成功的组合，就返回
				if (dfs(nums, s, i + j)) return nums;
				// 回溯
				nums.pop_back();
				nums.pop_back();
			}
		}
		return nums;
	}
};

#endif //CPP_0842__SOLUTION1_H_
