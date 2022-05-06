/**
 * @author ooooo
 * @date 2021/4/11 07:57 
 */

#ifndef CPP_1812__SOLUTION1_H_
#define CPP_1812__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	bool squareIsWhite(string s) {
		return (s[1] - (s[0] - 'a')) % 2 == 0;
	}
};

#endif //CPP_1812__SOLUTION1_H_
