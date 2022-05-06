/**
 * @author ooooo
 * @date 2020/12/5 11:39 
 */

#ifndef CPP_0621__SOLUTION1_H_
#define CPP_0621__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * timeout
 */
class Solution {
 public:
	int leastInterval(vector<char> &tasks, int n) {
		// 每个任务的个数
		vector<int> task_counts(26, 0);
		for (auto &t: tasks) {
			task_counts[t - 'A']++;
		}
		// 每个任务的冷却时间
		vector<int> down_times(26, 0);
		auto f = [&](const int &i, const int &j) {
			if (down_times[i] == down_times[j]) {
				return task_counts[i] < task_counts[j];
			}
			return down_times[i] > down_times[j];
		};
		// 冷却时间最小堆

		priority_queue<int, vector<int>, decltype(f)> q(f);
		for (int i = 0; i < task_counts.size(); ++i) {
			// 任务个数大于0
			if (task_counts[i] > 0) {
				q.push(i);
			}
		}

		int ans = 0;
		while (!q.empty()) {
			int i = q.top();
			int down_time = down_times[i];
			if (down_time <= 0) {
				// 冷却时间为0，可以直接执行

				// 当前任务删除掉，当前任务冷却时间为n,任务减一
				q.pop();
				task_counts[i]--;
				down_times[i] = n;
				// 其他任务的冷却时间减一
				while (!q.empty()) {
					int j = q.top();
					q.pop();
					down_times[j] = max(0, down_times[j] - 1);
				}

				for (int k = 0; k < task_counts.size(); ++k) {
					// 任务个数大于0
					if (task_counts[k] > 0) {
						q.push(k);
					}
				}
			} else {
				// down_time 大于0，必须要等待
				while (!q.empty()) {
					int j = q.top();
					q.pop();
					down_times[j]--;
				}
				for (int k = 0; k < task_counts.size(); ++k) {
					// 任务个数大于0
					if (task_counts[k] > 0) {
						q.push(k);
					}
				}
			}
			ans++;
		}
		return ans;
	}
};

#endif //CPP_0621__SOLUTION1_H_
