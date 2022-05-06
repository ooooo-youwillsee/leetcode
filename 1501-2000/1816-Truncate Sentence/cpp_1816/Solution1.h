/**
 * @author ooooo
 * @date 2021/4/11 15:50 
 */

#ifndef CPP_1816__SOLUTION1_H_
#define CPP_1816__SOLUTION1_H_

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
 public:
	string truncateSentence(string s, int k) {
		istringstream in(s);
		string w;
		string ans = "";
		while (k && (in >> w)) {
			ans += w;
			k--;
			if (k > 0) {
				ans += " ";
			}
		}
		return ans;
	}
};

#endif //CPP_1816__SOLUTION1_H_
