/**
 * @author ooooo
 * @date 2021/4/10 20:21 
 */

#ifndef CPP_030__SOLUTION1_H_
#define CPP_030__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int magicTower(vector<int> &nums) {
		long long sum = 1;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			sum += nums[i];
		}
		if (sum <= 0) return -1;

		priority_queue<long long> pq;
		long long cur = 1;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cur += nums[i];
			if (nums[i] < 0) {
				pq.push(-nums[i]);
			}
			if (cur <= 0) {
				cur += pq.top();
				pq.pop();
				ans++;
			}

		}
		return ans;
	}
};

#endif //CPP_030__SOLUTION1_H_
