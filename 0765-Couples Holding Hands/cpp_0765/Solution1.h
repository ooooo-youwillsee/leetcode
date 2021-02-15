/**
 * @author ooooo
 * @date 2021/2/14 09:42 
 */

#ifndef CPP_0765__SOLUTION1_H_
#define CPP_0765__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

// dfs , 可以优化
// 理解最重要的一点 比如 [0,x,1,z]， 要使0，1在一起的话，就是[0,1,x,z]或者[z,x,1,0]
// 上述的这两种情况，x,z只是相对位置发生了改变，而实际的交换次数并没有改变
class Solution {
 public:
	int ans = 0;
	void dfs(unordered_map<int, int> &m, vector<int> &row, int i, int count) {
		if (i == row.size()) {
			ans = min(ans, count);
			return;
		}
		int a = row[i], b = 0;
		if (a % 2 == 0) {
			b = a + 1;
		} else {
			b = a - 1;
		}

		int bIndex = m[b];
		if (abs(bIndex - i) == 1) {
			dfs(m, row, i + 2, count);
			return;
		}
		swap(row[i + 1], row[bIndex]);
		m[b] = i + 1;
		m[row[bIndex]] = bIndex;
		dfs(m, row, i, count + 1);
	}

	int minSwapsCouples(vector<int> &row) {
		unordered_map<int, int> m;
		for (int i = 0; i < row.size(); ++i) {
			m[row[i]] = i;
		}
		ans = INT_MAX;
		dfs(m, row, 0, 0);
		return ans;
	}
};

#endif //CPP_0765__SOLUTION1_H_
