
/**
 * @author ooooo
 * @date 2021/1/26 13:53 
 */

#ifndef CPP_1128__SOLUTION1_H_
#define CPP_1128__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
	int numEquivDominoPairs(vector<vector<int>> &dominoes) {
		int ans = 0;
		for (int i = 0; i < dominoes.size(); ++i) {
			sort(dominoes[i].begin(), dominoes[i].end());
		}
		sort(dominoes.begin(), dominoes.end());
		int cur = 1;
		for (int i = 1; i < dominoes.size(); i++) {
			if (dominoes[i] == dominoes[i - 1]) {
				cur++;
				ans += cur - 1;
			} else {
				cur = 1;
			}
		}
		return ans;
	}
};

#endif //CPP_1128__SOLUTION1_H_
