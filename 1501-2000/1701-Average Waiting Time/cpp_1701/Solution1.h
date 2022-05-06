/**
 * @author ooooo
 * @date 2021/1/24 18:08 
 */

#ifndef CPP_1701__SOLUTION1_H_
#define CPP_1701__SOLUTION1_H_


#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution2 {

	double averageWaitingTime(vector<vector<int>> &customers) {
		long long total_wait = 0;
		int n = customers.size();
		long long last_finish = 0;
		for (int i = 0; i < n; ++i) {
			long long cur_time = 0;
			if (customers[i][0] >= last_finish) {
				cur_time = customers[i][0];
			} else {
				cur_time = last_finish;
			}
			total_wait += cur_time + customers[i][1] - customers[i][0];
			last_finish = cur_time + customers[i][1];
		}
		return 1.0 * total_wait / n;
	}
};

#endif //CPP_1701__SOLUTION1_H_
