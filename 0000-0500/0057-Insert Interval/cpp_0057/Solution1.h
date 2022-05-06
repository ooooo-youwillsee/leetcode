/**
 * @author ooooo
 * @date 2020/11/4 17:26 
 */

#ifndef CPP_0057__SOLUTION1_H_
#define CPP_0057__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
		if (intervals.empty()) return {newInterval};
		vector<vector<int>> ans;
		int left = newInterval[0], right = newInterval[1];
		bool inserted = false;
		for (int i = 0; i < intervals.size(); ++i) {
			int l = intervals[i][0], r = intervals[i][1];
			if (right < l) {
				if (!inserted) {
					ans.push_back({left, right});
					inserted = true;
				}
				ans.push_back(intervals[i]);
			} else if (left > r) {
				ans.push_back(intervals[i]);
			} else {
				left = min(left, l);
				right = max(right, r);
			}
		}
		if (!inserted) {
			ans.push_back({left, right});
		}
		return ans;
	}
};

#endif //CPP_0057__SOLUTION1_H_
