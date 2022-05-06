/**
 * @author ooooo
 * @date 2020/12/5 12:49 
 */

#ifndef CPP_0621__SOLUTION2_H
#define CPP_0621__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 *
 */
class Solution {
 public:
	int leastInterval(vector<char> &tasks, int n) {
		vector<int> task_counts(26);
		for (auto &t: tasks) {
			task_counts[t - 'A']++;
		}
		sort(task_counts.begin(), task_counts.end(), greater<int>());
		int cnt = 1, max_count = task_counts[0]; // 默认有一个，就是最大的
		for (int i = 1; i < task_counts.size(); ++i) {
			if (task_counts[i] == max_count) cnt++;
		}
		return max((int)tasks.size(), (max_count - 1) * (n + 1) + cnt);
	}
};

#endif //CPP_0621__SOLUTION2_H_
