/**
 * @author ooooo
 * @date 2020/11/15 09:39 
 */

#ifndef CPP_1629__SOLUTION1_H_
#define CPP_1629__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	char slowestKey(vector<int> &releaseTimes, string keysPressed) {
		vector<pair<int, char>> ans;
		int prev_time = 0;
		for (int i = 0; i < keysPressed.size(); ++i) {
			ans.push_back(make_pair(releaseTimes[i] - prev_time, keysPressed[i]));
			prev_time = releaseTimes[i];
		}
		sort(ans.begin(), ans.end(), greater<pair<int, char>>());
		return ans[0].second;
	}
}

#endif //CPP_1629__SOLUTION1_H_
