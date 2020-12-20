/**
 * @author ooooo
 * @date 2020/12/20 12:05 
 */

#ifndef CPP_0316__SOLUTION1_H_
#define CPP_0316__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 可以用双端队列或者数组加快速度
 */
class Solution {
 public:
	string removeDuplicateLetters(string s) {
		stack<char> stack;
		// 计数
		unordered_map<char, int> m;
		// 用于判断栈中字符是否存在
		unordered_set<char> set;
		for (auto c: s) {
			m[c]++;
		}
		for (auto c: s) {
			// 栈顶的元素大于当前的元素 &&  栈中不包含当前元素 , 特例： "abacb"
			// m[stack.top()] > 0 表示在后面的字符串中还有此元素
			while (!stack.empty() && stack.top() >= c && m[stack.top()] > 0 && !set.count(c)) {
				char x = stack.top();
				stack.pop();
				set.erase(x);
			}
			if (!set.count(c)) {
				stack.push(c);
				set.insert(c);
			}
			// 每个元素个数减一
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

#endif //CPP_0316__SOLUTION1_H_
