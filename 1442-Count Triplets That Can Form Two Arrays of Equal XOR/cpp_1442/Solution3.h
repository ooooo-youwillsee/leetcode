/**
 * @author ooooo
 * @date 2021/5/22 11:38 
 */

#ifndef CPP_1442__SOLUTION3_H_
#define CPP_1442__SOLUTION3_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int countTriplets(vector<int>& arr) {
		int n = arr.size();
		vector<int> pre(n+1);
		for (int i = 0; i < n; i++) {
			pre[i+1] = pre[i] ^ arr[i];
		}

		// pre[j] ^ pre[i] = pre[k+1] ^ pre[j]
		int ans = 0;
		unordered_map<int, int> m, len;
		for (int i = 0; i < n; i++) {
			if (m.count(pre[i+1])) {
				ans += (i * m[pre[i+1]] - len[pre[i+1]]);
			}
			// 可能存在异或值为0的情况
			len[pre[i]] += i;
			m[pre[i]] ++;
		}
		return ans;
	}
};

#endif //CPP_1442__SOLUTION3_H_
