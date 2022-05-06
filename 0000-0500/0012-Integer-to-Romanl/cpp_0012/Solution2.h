/**
 * @author ooooo
 * @date 2021/5/14 18:17 
 */

#ifndef CPP_0012__SOLUTION2_H_
#define CPP_0012__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	string intToRoman(int num) {
		int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string reps[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		string ans = "";
		int i = 0;
		while (i < sizeof(values) / sizeof(values[0])) {
			while (num >= values[i]) {
				num -= values[i];
				ans += reps[i];
			}
			i++;
		}
		return ans;
	}
};

#endif //CPP_0012__SOLUTION2_H_
