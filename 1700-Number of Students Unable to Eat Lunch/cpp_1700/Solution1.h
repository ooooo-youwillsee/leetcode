/**
 * @author ooooo
 * @date 2021/1/24 18:07 
 */

#ifndef CPP_1700__SOLUTION1_H_
#define CPP_1700__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution2 {

	int countStudents(vector<int> &students, vector<int> &sandwiches) {
		deque<int> q(students.begin(), students.end());
		int i = 0, cnt = students.size(), prev_i = 0;
		while (!q.empty()) {
			auto stu = q.front();
			q.pop_front();
			if (stu == sandwiches[i]) {
				prev_i = i;
				i++;
			} else {
				q.push_back(stu);
			}
			cnt--;
			if (cnt < 0) {
				if (prev_i == i) {
					break;
				}
				prev_i = i;
				cnt = students.size();
			}
		}
		return q.size();
	}
};

#endif //CPP_1700__SOLUTION1_H_
