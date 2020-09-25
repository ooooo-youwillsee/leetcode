/**
 * @author ooooo
 * @date 2020/9/25 13:43 
 */

#ifndef CPP_0012__SOLUTION1_H_
#define CPP_0012__SOLUTION1_H_

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:

	string intToRoman(int num) {
		vector<string> vec;

		int a = num % 10;
		if (a == 4) vec.emplace_back("IV");
		else if (a == 9) vec.emplace_back("IX");
		else if (a >= 5) vec.emplace_back("V" + string(a - 5, 'I'));
		else vec.emplace_back(string(a, 'I'));
		num -= a;

		if (num > 0) {
			int b = num % 100;
			if (b == 40) vec.emplace_back("XL");
			else if (b == 90) vec.emplace_back("XC");
			else if (a >= 50) vec.emplace_back("L" + string((b - 50) / 10, 'X'));
			else vec.emplace_back(string(b, 'X'));
			num -= b;
		}

		if (num > 0) {
			int c = num % 1000;
			if (c == 400) vec.emplace_back("CD");
			else if (c == 900) vec.emplace_back("CM");
			else if (c >= 500) vec.emplace_back("D" + string((c - 500) / 100, 'C'));
			else vec.emplace_back(string(c, 'C'));
			num -= c;
		}

		vec.emplace_back(string(num / 1000, 'M'));

		reverse(vec.begin(), vec.end());
		string s;
		for (auto &item : vec) {
			s += item;
		}
		return s;
	}
};

#endif //CPP_0012__SOLUTION1_H_
