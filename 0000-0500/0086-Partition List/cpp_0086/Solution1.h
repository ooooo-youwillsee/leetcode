/**
 * @author ooooo
 * @date 2021/1/4 16:16 
 */

#ifndef CPP_0086__SOLUTION1_H_
#define CPP_0086__SOLUTION1_H_

#include "ListNode.h"

class Solution {
 public:
	ListNode *partition(ListNode *head, int x) {
		ListNode *dummyHead = new ListNode(-1);
		dummyHead->next = head;

		ListNode *cur = dummyHead;
		while (cur && cur->next) {
			if (cur->next->val >= x) {
				break;
			}
			cur = cur->next;
		}

		ListNode *prev = cur;
		while (cur && cur->next) {
			if (cur->next->val < x) {
				auto prev_next = prev->next;
				auto cur_next = cur->next->next;
				prev->next = cur->next;
				prev->next->next = prev_next;
				cur->next = cur_next;
				prev = prev->next;
				continue;
			}
			cur = cur->next;
		}
		return dummyHead->next;
	}
};

#endif //CPP_0086__SOLUTION1_H_
