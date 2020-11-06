/**
 * @author ooooo
 * @date 2020/11/6 20:38 
 */

#ifndef CPP_1356__SOLUTION1_H_
#define CPP_1356__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	vector<int> sortByBits(vector<int> &arr) {
		auto fn = [](int n) {
			int i = 0;
			while (n) {
				i++;
				n = n & (n - 1);
			}
			return i;
		};
		sort(arr.begin(), arr.end(), [&](int x, int y) {
			int c1 = fn(x), c2 = fn(y);
			return c1 == c2 ? x < y : c1 < c2;
		});
		return arr;
	}
};

#endif //CPP_1356__SOLUTION1_H_
