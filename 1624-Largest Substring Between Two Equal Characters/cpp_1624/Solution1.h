/**
 * @author ooooo
 * @date 2020/11/15 09:01 
 */

#ifndef CPP_1624__SOLUTION1_H_
#define CPP_1624__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution {
 public:

	int maxLengthBetweenEqualCharacters(string s) {
		int ans = -1;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = s.size() - 1; j >= i; --j) {
				if (s[j] == s[i] && j != i) {
					ans = max(ans, j - i - 1);
					break;
				}
			}
		}
		return ans;
	}
}

#endif //CPP_1624__SOLUTION1_H_
