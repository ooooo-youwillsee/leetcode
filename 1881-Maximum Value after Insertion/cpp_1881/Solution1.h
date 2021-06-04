/**
 * @author ooooo
 * @date 2021/5/31 10:17 
 */

#ifndef CPP_1881__SOLUTION1_H_
#define CPP_1881__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	string maxValue(string n, int x) {
		string ans = "";
		int i = 0;
		bool inserted = false;
		if (n[i] == '-') {
			i = 1;
			ans += n[0];
			while (i < n.size()) {
				if (!inserted && (n[i] - '0') > x) {
					ans += to_string(x);
					inserted = true;
				} else {
					ans += n[i];
					i++;
				}
			}
		} else {
			while (i < n.size()) {
				if (!inserted && (n[i] - '0') < x) {
					ans += to_string(x);
					inserted = true;
				} else {
					ans += n[i];
					i++;
				}
			}
		}
		if (!inserted) {
			ans += to_string(x);
		}
		return ans;
	}
};

#endif //CPP_1881__SOLUTION1_H_
