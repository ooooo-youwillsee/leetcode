/**
 * @author ooooo
 * @date 2021/5/22 11:37 
 */

#ifndef CPP_1442__SOLUTION1_H_
#define CPP_1442__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int countTriplets(vector<int> &arr) {
		int n = arr.size();
		vector<int> pre(n + 1);
		for (int i = 0; i < n; i++) {
			pre[i + 1] = pre[i] ^ arr[i];
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j; k < n; k++) {
					int a = pre[j] ^pre[i];
					int b = pre[k + 1] ^pre[j];
					if (a == b) ans++;
				}
			}
		}
		return ans;
	}
};
#endif //CPP_1442__SOLUTION1_H_
