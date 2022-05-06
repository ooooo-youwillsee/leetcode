/**
 * @author ooooo
 * @date 2021/3/6 16:09 
 */

#ifndef CPP_1642__SOLUTION1_H_
#define CPP_1642__SOLUTION1_H_

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 堆
class Solution {
 public:
	int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
		int n = heights.size();
		int i = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		int sum = 0;
		for (; i < n - 1; ++i) {
			int diff = heights[i + 1] - heights[i];
			if (diff > 0) {
				// 直接用梯子
				pq.push(diff);
				if (pq.size() > ladders) {
					// 改用砖块
					sum += pq.top();
					pq.pop();
				}
				if (sum > bricks) {
					return i;
				}
			}
		}
		return i;
	}
};

#endif //CPP_1642__SOLUTION1_H_
