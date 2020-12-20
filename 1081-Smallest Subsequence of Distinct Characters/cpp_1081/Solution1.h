/**
 * @author ooooo
 * @date 2020/12/20 12:45 
 */

#ifndef CPP_1081__SOLUTION1_H_
#define CPP_1081__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
	string smallestSubsequence(string s) {
		stack<char> stack;
		unordered_map<char, int> m;
		unordered_set<char> set;
		for (auto c: s) {
			m[c]++;
		}
		for (auto c: s) {
			while (!stack.empty() && stack.top() >= c && m[stack.top()] > 0 && !set.count(c)) {
				char x = stack.top();
				stack.pop();
				set.erase(x);
			}
			if (!set.count(c)) {
				stack.push(c);
				set.insert(c);
			}
			m[c]--;
		}
		string ans = "";
		while (!stack.empty()) {
			ans.push_back(stack.top());
			stack.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

#endif //CPP_1081__SOLUTION1_H_
