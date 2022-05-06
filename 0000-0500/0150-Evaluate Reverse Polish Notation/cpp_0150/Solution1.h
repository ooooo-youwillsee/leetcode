/**
 * @author ooooo
 * @date 2021/3/20 12:13 
 */

#ifndef CPP_0150__SOLUTION1_H_
#define CPP_0150__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:

	int evalRPN(vector<string> &tokens) {
		stack<int> s;
		for (int i = 0; i < tokens.size(); ++i) {
			if (tokens[i] == "+") {
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				s.push(y + x);
			} else if (tokens[i] == "-") {
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				s.push(y - x);
			} else if (tokens[i] == "*") {
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				s.push(y * x);
			} else if (tokens[i] == "/") {
				int x = s.top();
				s.pop();
				int y = s.top();
				s.pop();
				s.push(y / x);
			} else {
				s.push(stoi(tokens[i]));
			}
		}
		return s.top();
	}
};

#endif //CPP_0150__SOLUTION1_H_
