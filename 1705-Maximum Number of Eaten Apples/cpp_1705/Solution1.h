/**
 * @author ooooo
 * @date 2021/1/24 17:17 
 */

#ifndef CPP_1705__SOLUTION1_H_
#define CPP_1705__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
	int eatenApples(vector<int> &apples, vector<int> &days) {
		int n = apples.size();
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			q.push(make_pair(i + days[i] - 1, apples[i]));
			while (!q.empty()) {
				pair<int, int> x = q.top();
				q.pop();
				if (i <= x.first) {
					ans++;
					// 吃掉一个，个数减一
					x.second--;
					// 如果还有，重新添加到优先队列
					if (x.second > 0) {
						q.push(x);
					}
					break;
				}
			}
		}

		int i = n;
		while (true) {
			while (!q.empty()) {
				pair<int, int> x = q.top();
				q.pop();
				if (i <= x.first) {
					ans++;
					// 吃掉一个，个数减一
					x.second--;
					// 如果还有，重新添加到优先队列
					if (x.second > 0) {
						q.push(x);
					}
					break;
				}
			}
			if (q.empty()) break;
			i++;
		}
		return ans;
	}
};

#endif //CPP_1705__SOLUTION1_H_
