/**
 * @author ooooo
 * @date 2021/1/29 20:47 
 */

#ifndef CPP_1678__SOLUTION1_H_
#define CPP_1678__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:
	string interpret(string command) {
		string ans = "";
		for (int i = 0; i < command.size(); ++i) {
			char c = command[i];
			if (c == 'G') {
				ans += c;
			} else if (c == ')') {
				if (command[i - 1] == '(') {
					ans += 'o';
				} else {
					ans += "al";
				}
			}
		}
		return ans;
	}
};

#endif //CPP_1678__SOLUTION1_H_
