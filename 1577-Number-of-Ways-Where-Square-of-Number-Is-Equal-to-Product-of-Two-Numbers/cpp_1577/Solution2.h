/**
 * @author ooooo
 * @date 2020/9/7 15:17 
 */

#ifndef CPP_1577__SOLUTION2_H_
#define CPP_1577__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution1 {
 public:

	int numTriplets(vector<int> &nums1, vector<int> &nums2) {
		int count = 0;
		unordered_map<long long, int> m1;
		for (int j = 0; j < nums1.size(); ++j) {
			for (int k = j + 1; k < nums1.size(); ++k) {
				m1[(long long) nums1[j] * (long long) nums1[k]]++;
			}
		}

		unordered_map<long long, int> m2;
		for (int j = 0; j < nums2.size(); ++j) {
			for (int k = j + 1; k < nums2.size(); ++k) {
				m2[(long long) nums2[j] * (long long) nums2[k]]++;
			}
		}

		for (int i = 0; i < nums1.size(); ++i) {
			long long sum = (long long) nums1[i] * (long long) nums1[i];
			count += m2[sum];
		}

		for (int i = 0; i < nums2.size(); ++i) {
			long long sum = (long long) nums2[i] * (long long) nums2[i];
			count += m1[sum];
		}
		return count;
	}
};

#endif //CPP_1577__SOLUTION2_H_
