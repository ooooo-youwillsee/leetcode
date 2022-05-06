/**
 * @author ooooo
 * @date 2020/9/30 10:57 
 */

#ifndef CPP_0860__SOLUTION1_H_
#define CPP_0860__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool lemonadeChange(vector<int> &bills) {
		int bill_5 = 0, bill_10 = 0;
		for (auto &a :bills) {
			if (a == 5) {
				bill_5++;
			} else if (a == 10) {
				bill_10++;
				bill_5--;
			} else {
				if (bill_10 > 0) {
					bill_10--;
					bill_5--;
				} else {
					bill_5 -= 3;
				}
			}
			if (bill_10 < 0 || bill_5 < 0) return false;
		}
		return true;
	}
};

#endif //CPP_0860__SOLUTION1_H_
