/**
 * @author ooooo
 * @date 2021/3/18 17:59 
 */

#ifndef CPP_0092__SOLUTION1_H_
#define CPP_0092__SOLUTION1_H_

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:

	ListNode *reverse(ListNode *head, int cnt) {
		ListNode *cur = head, *prev = nullptr;
		while (cnt > 0) {
			ListNode *next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
			cnt--;
		}
		head->next = cur;
		return prev;
	}

	ListNode *reverseBetween(ListNode *head, int left, int right) {
		ListNode *dummyHead = new ListNode(-1);
		dummyHead->next = head;
		int cnt = 1;
		ListNode *cur = dummyHead;
		while (cnt < left) {
			cur = cur->next;
			cnt++;
		}

		ListNode *prev = cur;
		prev->next = reverse(prev->next, right - left + 1);
		return dummyHead->next;
	}
};

#endif //CPP_0092__SOLUTION1_H_
