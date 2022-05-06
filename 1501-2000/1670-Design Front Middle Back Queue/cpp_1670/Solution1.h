/**
 * @author ooooo
 * @date 2021/1/24 17:55 
 */

#ifndef CPP_1670__SOLUTION1_H_
#define CPP_1670__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

// https://leetcode-cn.com/contest/biweekly-contest-40/problems/design-front-middle-back-queue/
class FrontMiddleBackQueue {
 public:

	deque<int> nums;
	stack<int> help_stack;

	FrontMiddleBackQueue() {

	}

	void pushFront(int val) {
		nums.push_front(val);
	}

	void pushMiddle(int val) {
		int count = nums.size() / 2;
		while (count > 0) {
			help_stack.push(nums.front());
			nums.pop_front();
			count--;
		}
		nums.push_front(val);
		while (!help_stack.empty()) {
			nums.push_front(help_stack.top());
			help_stack.pop();
		}
	}

	void pushBack(int val) {
		nums.push_back(val);
	}

	int popFront() {
		if (nums.empty()) return -1;
		int ret = nums.front();
		nums.pop_front();
		return ret;
	}

	int popMiddle() {
		if (nums.empty()) return -1;
		int count = (nums.size() - 1) / 2;
		while (count > 0) {
			help_stack.push(nums.front());
			nums.pop_front();
			count--;
		}
		int ret = nums.front();
		nums.pop_front();
		while (!help_stack.empty()) {
			nums.push_front(help_stack.top());
			help_stack.pop();
		}
		return ret;
	}

	int popBack() {
		if (nums.empty()) return -1;
		int ret = nums.back();
		nums.pop_back();
		return ret;
	}
};

#endif //CPP_1670__SOLUTION1_H_
