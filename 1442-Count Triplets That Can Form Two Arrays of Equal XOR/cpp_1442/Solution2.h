/**
 * @author ooooo
 * @date 2021/5/22 11:37 
 */

#ifndef CPP_1442__SOLUTION2_H_
#define CPP_1442__SOLUTION2_H_

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

		// pre[j] ^ pre[i] = pre[k+1] ^ pre[j]
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int k = i + 1; k < n; k++) {
				if (pre[i] == pre[k + 1]) {
					ans += (k - i);
				}
			}
		}
		return ans;
	}
};
#endif //CPP_1442__SOLUTION2_H_
