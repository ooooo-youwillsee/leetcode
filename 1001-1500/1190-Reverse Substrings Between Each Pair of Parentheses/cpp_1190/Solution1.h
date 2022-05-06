/**
 * @author ooooo
 * @date 2021/5/26 13:25 
 */

#ifndef CPP_1190__SOLUTION1_H_
#define CPP_1190__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:
	string reverseParentheses(string s) {
		stack<char> sk;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ')') {
				string tmp = "";
				while (sk.top() != '(') {
					tmp += sk.top();
					sk.pop();
				}
				sk.pop();
				for (auto c :tmp) {
					sk.push(c);
				}
			} else {
				sk.push(s[i]);
			}
		}
		string ans = "";
		while (!sk.empty()) {
			ans += sk.top();
			sk.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}

};
#endif //CPP_1190__SOLUTION1_H_
