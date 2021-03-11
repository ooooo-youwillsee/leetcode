/**
 * @author ooooo
 * @date 2021/3/11 09:25 
 */

#ifndef CPP_0227__SOLUTION1_H_
#define CPP_0227__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:

	void calc(stack<long long> &numStack, stack<char> &opStack) {
		int x = numStack.top();
		numStack.pop();
		int y = numStack.top();
		numStack.pop();
		char c = opStack.top();
		opStack.pop();
		if (c == '+') {
			numStack.push(y + x);
		} else if (c == '-') {
			numStack.push(y - x);
		} else if (c == '*') {
			numStack.push(y * x);
		} else if (c == '/') {
			numStack.push(y / x);
		}
	}

	/*
	 * 测试用例
	 * 	"3+2*2"
			"1-1+1"
			"1-1-1"
			"2*3+4"
	 * */
	int calculate(string s) {
		int i = 0, n = s.size();
		stack<long long> numStack;
		stack<char> opStack;

		int sign = 1;
		while (i < n) {
			while (i < n && s[i] == ' ') i++;
			if (i >= n) break;

			if (s[i] == '-') {
				sign = -sign;
				i++;
				opStack.push('+');
				continue;
			}
			if (s[i] == '+' || s[i] == '*' || s[i] == '/') {
				opStack.push(s[i]);
				i++;
				continue;
			}

			long long num = 0;
			while (i < n && s[i] >= '0' && s[i] <= '9') {
				num = num * 10 + (s[i] - '0');
				i++;
			}
			numStack.push(num * sign);
			sign = 1;
			if (!opStack.empty() && (opStack.top() == '*' || opStack.top() == '/')) {
				calc(numStack, opStack);
			}
		}

		while (numStack.size() > 1) {
			calc(numStack, opStack);
		}
		return numStack.top();
	}
};

#endif //CPP_0227__SOLUTION1_H_
