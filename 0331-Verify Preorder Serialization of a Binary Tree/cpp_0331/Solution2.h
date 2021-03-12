/**
 * @author ooooo
 * @date 2021/3/12 20:00 
 */

#ifndef CPP_0331__SOLUTION2_H_
#define CPP_0331__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 插槽栈
class Solution {
 public:

	bool isValidSerialization(string preorder) {
		stack<int> s;
		s.push(1);
		int i = 0, n = preorder.size();
		while (i < n) {
			if (preorder[i] == ',') {
				i++;
			} else if (preorder[i] == '#') {
				if (s.empty()) {
					return false;
				}
				s.top() -= 1;
				if (s.top() == 0) {
					s.pop();
				}
				i++;
			} else {
				while (i < n && preorder[i] != ',') {
					i++;
				}
				i++;
				if (s.empty()) {
					return false;
				}
				s.top() -= 1;
				if (s.top() == 0) {
					s.pop();
				}
				s.push(2);
			}
		}
		return s.empty();
	}
};

#endif //CPP_0331__SOLUTION2_H_
