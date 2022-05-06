/**
 * @author ooooo
 * @date 2021/5/25 22:18 
 */

#ifndef CPP_1865__SOLUTION1_H_
#define CPP_1865__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class FindSumPairs {
 public:
	unordered_map<int, int> m;
	vector<int> nums1, nums2;
	FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
		this->nums1 = nums1;
		this->nums2 = nums2;
		for (auto num: nums2) {
			m[num]++;
		}
		sort(this->nums1.begin(), this->nums1.end());
	}

	void add(int index, int val) {
		m[nums2[index]]--;
		nums2[index] += val;
		m[nums2[index]]++;
	}

	int count(int tot) {
		int ans = 0;
		for (auto num1 : nums1) {
			if (num1 > tot) break;
			int t = tot - num1;
			ans += m[t];
		}
		return ans;
	}
};

#endif //CPP_1865__SOLUTION1_H_
