/**
 * @author ooooo
 * @date 2020/11/27 13:54 
 */

#ifndef CPP_0315__SOLUTION2_H_
#define CPP_0315__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	vector<int> nums, tmp, indexes, ans, tmp_indexes;

	void merge(int l, int mid, int r) {
		copy(nums.begin() + l, nums.begin() + r + 1, tmp.begin() + l);
		copy(indexes.begin() + l, indexes.begin() + r + 1, tmp_indexes.begin() + l);
		int i = l, j = mid + 1;
		int k = l;

		while (i <= mid && j <= r) {
			if (tmp[i] <= tmp[j]) {
				nums[k] = tmp[i];
				indexes[k] = tmp_indexes[i];
				// 经典！！！
				ans[tmp_indexes[i]] += (j - mid - 1);
				i++;
			} else {
				//for (int p = i; p <= mid; ++p) {
				//	ans[tmp_indexes[p]]++;
				//}
				nums[k] = tmp[j];
				indexes[k] = tmp_indexes[j];
				j++;
			}
			k++;
		}

		while (i <= mid) {
			nums[k] = tmp[i];
			indexes[k] = tmp_indexes[i];
			ans[tmp_indexes[i]] += (j - mid - 1);
			i++;
			k++;
		}
		while (j <= r) {
			nums[k] = tmp[j];
			indexes[k] = tmp_indexes[j];
			j++;
			k++;
		}
	}

	void mergeSort(int l, int r) {
		if (l >= r) return;
		int mid = l + (r - l) / 2;
		mergeSort(l, mid);
		mergeSort(mid + 1, r);
		merge(l, mid, r);
	}

	vector<int> countSmaller(vector<int> &nums) {
		int n = nums.size();
		this->nums = nums;
		ans.assign(n, 0);
		tmp.assign(n, 0);
		indexes.assign(n, 0);
		tmp_indexes.assign(n, 0);
		for (int i = 0; i < n; ++i) {
			indexes[i] = i;
		}
		mergeSort(0, nums.size() - 1);

		//for (auto &num : this->nums) {
		//	cout << num << " ";
		//}
		//cout << endl;
		return ans;
	}
};

#endif //CPP_0315__SOLUTION2_H_
