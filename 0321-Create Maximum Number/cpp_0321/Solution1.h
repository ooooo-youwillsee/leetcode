/**
 * @author ooooo
 * @date 2020/12/3 12:27 
 */

#ifndef CPP_0321__SOLUTION1_H_
#define CPP_0321__SOLUTION1_H_

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:

	// 自定义比较函数， 处理情况 num1:[6,7]  num2:[6,0,4] k=5
	bool compare(vector<int> &nums1, int i, vector<int> &nums2, int j) {
		int m = nums1.size(), n = nums2.size();
		while (i < m && j < n) {
			if (nums1[i] != nums2[j]) {
				return nums1[i] > nums2[j];
			}
			i++;
			j++;
		}
		return i != m;
	}

	vector<int> maxSubArray(vector<int> &nums, int k) {
		vector<int> s;
		for (int i = 0, n = nums.size(); i < n; ++i) {
			int num = nums[i];
			while (!s.empty() && num > s.back() && s.size() + n - 1 - i >= k) {
				s.pop_back();
			}
			s.push_back(num);
		}
		return {s.begin(), s.begin() + k};
	}

	vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
		int i = 0, m = nums1.size(), j = 0, n = nums2.size();
		vector<int> ans(m + n, 0);
		int k = 0;
		while (i < m && j < n) {
			if (compare(nums1, i, nums2, j) > 0) {
				ans[k++] = nums1[i++];
			} else {
				ans[k++] = nums2[j++];
			}
		}
		while (i < m) {
			ans[k++] = nums1[i++];
		}
		while (j < n) {
			ans[k++] = nums2[j++];
		}
		return ans;
	}

	vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
		int m = nums1.size(), n = nums2.size();
		vector<int> ans(k, 0);
		for (int i = 0, j = min(k, m); i <= j; ++i) {
			if (i > m || k - i > n) continue;
			auto vec1 = maxSubArray(nums1, i);
			auto vec2 = maxSubArray(nums2, k - i);
			auto vec = merge(vec1, vec2);
			ans = max(ans, vec);
		}
		return ans;
	}

};

#endif //CPP_0321__SOLUTION1_H_
