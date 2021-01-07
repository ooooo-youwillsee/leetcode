/**
 * @author ooooo
 * @date 2021/1/7 17:08 
 */

#ifndef CPP_0547__SOLUTION1_H_
#define CPP_0547__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	int findCircleNum(vector<vector<int>> &isConnected) {
		int n = isConnected.size();
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
		int ans = n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (isConnected[i][j]) {
					ans -= connect(p, i, j);
				}
			}
		}
		return ans;
	}

	int find(vector<int> &p, int i) {
		if (i == p[i]) return i;
		int pi = find(p, p[i]);
		p[i] = pi;
		return pi;
	}

	int connect(vector<int> &p, int i, int j) {
		int pi = find(p, i), pj = find(p, j);
		if (pi == pj) return 0;
		p[pi] = pj;
		return 1;
	}
};

#endif //CPP_0547__SOLUTION1_H_
