/**
 * @author ooooo
 * @date 2020/11/19 09:02 
 */

#ifndef CPP_0134__SOLUTION1_H_
#define CPP_0134__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int i = 0, n = gas.size();
		while (i < n) {
			int g = 0, c = 0, cnt = 0;
			while (cnt < n) {
				int j = (i + cnt) % n;
				g += gas[j];
				c += cost[j];
				// 需要汽油多
				if (c > g) {
					break;
				}
				cnt++;
			}
			if (cnt == n) {
				return i;
			}
			i = i + cnt + 1;
		}
		return -1;
	}
};

#endif //CPP_0134__SOLUTION1_H_


