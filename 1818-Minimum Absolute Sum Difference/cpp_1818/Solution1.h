/**
 * @author ooooo
 * @date 2021/4/11 15:56 
 */

#ifndef CPP_1818__SOLUTION1_H_
#define CPP_1818__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:

	int minAbsoluteSumDiff(vector<int> nums1, vector<int> nums2) {
		int n = nums1.size();
		vector<long long> pre(n + 1);
		for (int i = 0; i < n; ++i) {
			pre[i + 1] = pre[i] + abs(nums1[i] - nums2[i]);
		}
		long long ans = pre[n];
		if (ans == 0) {
			return 0;
		}
		int mod = 1e9 + 7;
		sort(nums1.begin(), nums1.end());
		for (int i = 0; i < n; ++i) {
			long long t = (pre[i] + pre[n] - pre[i + 1]) % mod;
			auto it = lower_bound(nums1.begin(), nums1.end(), nums2[i]);
			if (it == nums1.end()) {
				it = nums1.end() - 1;
			}
			ans = min(t + abs(*it - nums2[i]), ans);
			if (it - 1 >= nums1.begin()) {
				ans = min(t + abs(*(it - 1) - nums2[i]), ans);
			}
			if (it + 1 < nums1.end()) {
				ans = min(t + abs(*(it + 1) - nums2[i]), ans);
			}
		}
		return ans % mod;
	}

};

#endif //CPP_1818__SOLUTION1_H_
