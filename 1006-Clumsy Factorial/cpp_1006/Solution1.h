/**
 * @author ooooo
 * @date 2021/4/1 18:03 
 */

#ifndef CPP_1006__SOLUTION1_H_
#define CPP_1006__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:

	vector<string> ops = {"*", "/", "+", "-"};

	void calc(stack<int> &s, string &op) {
		int x = s.top();
		s.pop();
		int y = s.top();
		s.pop();
		if (op == "*") {
			s.push(y * x);
		} else if (op == "/") {
			s.push(y / x);
		} else if (op == "+") {
			s.push(y + x);
		} else {
			s.push(y - x);
		}
	}

	int clumsy(int N) {
		int i = 0;
		stack<int> s;
		stack<string> op;
		s.push(N);
		while (N > 1) {
			N--;
			if (ops[i] == "*" || ops[i] == "/") {
				s.push(N);
				calc(s, ops[i]);
			} else if (ops[i] == "-") {
				op.push("+");
				s.push(-1 * N);
			} else {
				op.push("+");
				s.push(N);
			}
			i = (i + 1) % ops.size();
		}
		while (s.size() > 1) {
			string p = op.top();
			op.pop();
			calc(s, p);
		}
		return s.top();
	}
};

#endif //CPP_1006__SOLUTION1_H_
