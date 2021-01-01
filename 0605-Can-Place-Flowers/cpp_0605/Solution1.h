/**
 * @author ooooo
 * @date 2021/1/1 09:57 
 */

#ifndef CPP_0605__SOLUTION1_H_
#define CPP_0605__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool canPlaceFlowers(vector<int> &f, int n) {
		if (n == 0) return true;
		int x = f.size();
		if (x == 1 && f[0] == 0 && n == 1) return true;
		for (int i = 0; i < x; i++) {
			if (f[i] == 0) {
				bool can = false;
				if (i == 0 && i + 1 < x && f[i + 1] == 0) can = true;
				else if (i == x - 1 && i - 1 >= 0 && f[i - 1] == 0) can = true;
				else if (i + 1 < x && i - 1 >= 0 && f[i - 1] == 0 && f[i + 1] == 0) can = true;
				if (can) {
					n--;
					f[i] = 1;
					if (n == 0) return true;
				}
			}
		}
		return n == 0;
	}
};

#endif //CPP_0605__SOLUTION1_H_
