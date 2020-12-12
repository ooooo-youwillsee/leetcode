/**
 * @author ooooo
 * @date 2020/12/12 20:27 
 */

#ifndef CPP_1562__SOLUTION2_H_
#define CPP_1562__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int findLatestStep(vector<int> &arr, int m) {
		int n = arr.size();
		if (m == n) return n;
		unordered_map<int, int> index2len, len2count;
		int prev_i = -1;

		for (int i = 0; i < n; ++i) {
			int k = arr[i];
			int left_len = index2len[k - 1], right_len = index2len[k + 1];
			int new_len = left_len + right_len + 1;
			index2len[k - left_len] = new_len;
			index2len[k + right_len] = new_len;
			len2count[new_len] += new_len;
			len2count[left_len] -= left_len;
			len2count[right_len] -= right_len;
			// m的长度还存在，就记录下
			if (len2count[m]) {
				prev_i = i + 1;
			}
		}
		return prev_i;
	}
};

#endif //CPP_1562__SOLUTION2_H_
