]/**
 * @author ooooo
 * @date 2021/3/10 11:52 
 */

#ifndef CPP_0224__SOLUTION1_H_
#define CPP_0224__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:

	void calc(stack<long long> &numStack, stack<char> &opStack) {
		long long x = numStack.top();
		numStack.pop();
		long long y = numStack.top();
		numStack.pop();
		char op = opStack.top();
		opStack.pop();
		if (op == '+') {
			numStack.push(y + x);
		} else if (op == '-') {
			numStack.push(y - x);
		}
	}

	// 测试用例
	// "(7)-(0)+(4)"
	// "-2+ 1"
	int calculate(string s) {
		int i = 0, n = s.size();
		stack<long long> numStack;
		numStack.push(0);
		stack<char> opStack;
		opStack.push('+');

		while (i < n) {
			while (i < n && s[i] == ' ') i++;
			if (i >= n) break;

			if (s[i] == '+' || s[i] == '-' || s[i] == '(') {
				opStack.push(s[i]);
				i++;
				continue;
			}
			if (s[i] == ')') {
				while (!opStack.empty() && opStack.top() != '(') {
					calc(numStack, opStack);
				}
				opStack.pop();
				if (!opStack.empty() && opStack.top() == '-') {
					calc(numStack, opStack);
				}
				i++;
				continue;
			}

			long long num = 0;
			while (i < n && s[i] >= '0' && s[i] <= '9') {
				num = num * 10 + s[i] - '0';
				i++;
			}

			numStack.push(num);
			if (!opStack.empty() && opStack.top() == '-') {
				calc(numStack, opStack);
			}
		}
		while (numStack.size() > 1) {
			calc(numStack, opStack);
		}
		return numStack.top();
	}
};

#endif //CPP_0224__SOLUTION1_H_
