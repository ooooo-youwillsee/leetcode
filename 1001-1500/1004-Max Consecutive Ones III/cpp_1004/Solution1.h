/**
 * @author ooooo
 * @date 2021/2/19 09:26 
 */

#ifndef CPP_1004__SOLUTION1_H_
#define CPP_1004__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 用队列存储位置，空间换时间
class Solution {
 public:
	int longestOnes(vector<int> &A, int K) {
		queue<int> q;
		int n = A.size();
		int l = 0, r = 0;
		int ans = 0;
		while (r < n) {
			if (A[r] == 0) {
				if (K == 0) {
					l = r + 1;
					r++;
					continue;
				}
				if (q.size() == K) {
					l = q.front() + 1;
					q.pop();
				}
				q.push(r);
			}
			ans = max(ans, r - l + 1);
			r++;
		}
		return ans;
	}
};

#endif //CPP_1004__SOLUTION1_H_
