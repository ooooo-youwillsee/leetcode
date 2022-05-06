/**
 * @author ooooo
 * @date 2020/9/7 15:09 
 */

#ifndef CPP_1577__SOLUTION1_H_
#define CPP_1577__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * timeout
 */
class Solution1 {
 public:

	int compute(vector<int> &nums1, vector<int> &nums2) {
		int count = 0;
		for (int i = 0; i < nums1.size(); ++i) {
			long long sum = (long long) nums1[i] * (long long) nums1[i];
			for (int j = 0; j < nums2.size(); ++j) {
				for (int k = j + 1; k < nums2.size(); ++k) {
					if (sum == (long long) nums2[j] * (long long) nums2[k]) {
						count++;
					}
				}
			}
		}
		return count;
	}

	int numTriplets(vector<int> &nums1, vector<int> &nums2) {
		return compute(nums1, nums2) + compute(nums2, nums1);
	}
};

#endif //CPP_1577__SOLUTION1_H_
