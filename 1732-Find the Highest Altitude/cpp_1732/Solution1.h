/**
 * @author ooooo
 * @date 2021/2/28 13:08 
 */

#ifndef CPP_1732__SOLUTION1_H_
#define CPP_1732__SOLUTION1_H_

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

	int largestAltitude(vector<int> &gain) {
		int ans = 0, cur = 0;
		for (int i = 0; i < gain.size(); ++i) {
			cur += gain[i];
			ans = max(ans, cur);
		}
		return ans;
	}
};

#endif //CPP_1732__SOLUTION1_H_
