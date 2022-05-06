/**
 * @author ooooo
 * @date 2021/2/28 13:09 
 */

#ifndef CPP_1736__SOLUTION1_H_
#define CPP_1736__SOLUTION1_H_



#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
#include <numeric>

using namespace std;

class Solution {

 public:

	string maximumTime(string time) {
		if (time[0] == '?') {
			if (time[1] == '?' || ('0' <= time[1] && time[1] <= '3')) {
				time[0] = '2';
			} else {
				time[0] = '1';
			}
		}
		if (time[1] == '?') {
			time[1] = time[0] == '2' ? '3' : '9';
		}
		if (time[3] == '?') {
			time[3] = '5';
		}
		if (time[4] == '?') {
			time[4] = '9';
		}
		return time;
	}
};

#endif //CPP_1736__SOLUTION1_H_
