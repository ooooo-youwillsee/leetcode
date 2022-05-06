/**
 * @author ooooo
 * @date 2020/12/24 17:12 
 */

#ifndef CPP_0135__SOLUTION2_H_
#define CPP_0135__SOLUTION2_H_

#include <iostream>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:
	int candy(vector<int> &ratings) {
		int n = ratings.size();
		vector<int> candy(n, 1);
		for (int i = 1; i < n; ++i) {
			if (ratings[i] > ratings[i - 1]) {
				candy[i] = max(candy[i], candy[i - 1] + 1);
			}
		}
		for (int i = n - 2; i >= 0; --i) {
			if (ratings[i] > ratings[i + 1]) {
				candy[i] = max(candy[i], candy[i + 1] + 1);
			}
		}
		return accumulate(candy.begin(), candy.end(), 0);
	}
};

#endif //CPP_0135__SOLUTION2_H_
