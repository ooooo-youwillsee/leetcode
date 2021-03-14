/**
 * @author ooooo
 * @date 2021/3/14 14:56 
 */

#ifndef CPP_1780__SOLUTION1_H_
#define CPP_1780__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:

	bool checkPowersOfThree(int n) {
		int num = n;
		while (num) {
			if (num % 3 != 0) {
				num--;
			}
			if (num % 3 != 0) return false;
			num = num / 3;
		}
		return true;
	}
};

#endif //CPP_1780__SOLUTION1_H_
