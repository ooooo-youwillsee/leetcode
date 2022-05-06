/**
 * @author ooooo
 * @date 2020/11/28 09:11 
 */

#ifndef CPP_0493__SOLUTION1_H_
#define CPP_0493__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	vector<long long> tmp;
	int ans = 0;

	void count(vector<int> &nums, int l, int mid, int r) {
		int i = l, j = mid + 1;
		while (i <= mid && j <= r) {
			if ((long)nums[i] > (long)2 * nums[j]) {
				j++;
				ans += (mid - i + 1);
			} else {
				i++;
			}
		}
	}

	void merge(vector<int> &nums, int l, int mid, int r) {
		count(nums, l, mid, r);
		copy(nums.begin() + l, nums.begin() + r + 1, tmp.begin() + l);

		int i = l, j = mid + 1;
		int k = l;
		while (i <= mid && j <= r) {
			if (tmp[i] < tmp[j]) {
				nums[k] = tmp[i];
				i++;
			} else {
				nums[k] = tmp[j];
				j++;
			}
			k++;
		}
		while (i <= mid) {
			nums[k] = tmp[i];
			i++;
			k++;
		}

		while (j <= r) {
			nums[k] = tmp[j];
			j++;
			k++;
		}
	}

	void mergeSort(vector<int> &nums, int l, int r) {
		if (l >= r) return;
		int mid = l + (r - l) / 2;
		mergeSort(nums, l, mid);
		mergeSort(nums, mid + 1, r);
		merge(nums, l, mid, r);
	}

	int reversePairs(vector<int> &nums) {
		int n = nums.size();
		tmp.assign(n, 0);
		mergeSort(nums, 0, n - 1);
		//for (int i = 0; i < n; ++i) {
		//	cout << nums[i] << " ";
		//}
		//cout << endl;
		return ans;
	}
};

#endif //CPP_0493__SOLUTION1_H_
