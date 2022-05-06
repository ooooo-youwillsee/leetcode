/**
 * @author ooooo
 * @date 2020/12/11 09:11 
 */

#ifndef CPP_0649__SOLUTION1_H_
#define CPP_0649__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
	string predictPartyVictory(string senate) {
		queue<int> R, D;
		int n = senate.size();
		for (int i = 0; i < n; ++i) {
			if (senate[i] == 'R') {
				R.push(i);
			} else {
				D.push(i);
			}
		}

		while (!R.empty() && !D.empty()) {
			if (R.front() < D.front()) {
				R.push(R.front() + n);
			} else {
				D.push(D.front() + n);
			}
			D.pop();
			R.pop();
		}

		return D.empty() ? "Radiant" : "Dire";
	}
};

#endif //CPP_0649__SOLUTION1_H_
