/**
 * @author ooooo
 * @date 2020/11/20 09:11 
 */

#ifndef CPP_0147__SOLUTION1_H_
#define CPP_0147__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:

	void insert(ListNode *dummyHead, ListNode *node) {
		ListNode *cur = dummyHead;
		while (cur->next) {
			if (node->val <= cur->next->val) {
				ListNode *next = cur->next;
				cur->next = node;
				node->next = next;
				return;
			}
			cur = cur->next;
		}
		cur->next = node;
	}

	ListNode *insertionSortList(ListNode *head) {
		ListNode *dummyHead = new ListNode(-1);
		ListNode *cur = head;
		while (cur) {
			ListNode *next = cur->next;
			cur->next = nullptr;
			insert(dummyHead, cur);
			cur = next;
		}
		return dummyHead->next;
	}
};

#endif //CPP_0147__SOLUTION1_H_
