/**
 * @author ooooo
 * @date 2021/4/10 11:48 
 */

#ifndef CPP_10_03__SOLUTION1_H_
#define CPP_10_03__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int search(vector<int> &arr, int target) {
		int n = arr.size();
		int l = 0, r = n - 1;
		int ans = INT_MAX;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (arr[l] < arr[mid]) {
				if (arr[l] <= target && target <= arr[mid]) {
					auto it = lower_bound(arr.begin() + l, arr.begin() + mid + 1, target);
					if (it != arr.end() && *it == target) {
						ans = min(ans, (int) (it - arr.begin()));
					}
				}
				l = mid + 1;
			} else if (arr[mid] < arr[r]) {
				if (arr[mid] <= target && target <= arr[r]) {
					auto it = lower_bound(arr.begin() + mid, arr.begin() + r + 1, target);
					if (it != arr.end() && *it == target) {
						ans = min(ans, (int) (it - arr.begin()));
					}
				}
				r = mid;
			} else {
				while (l <= r) {
					if (arr[l] == target) {
						ans = min(l, ans);
					}
					l++;
				}
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
};

#endif //CPP_10_03__SOLUTION1_H_
